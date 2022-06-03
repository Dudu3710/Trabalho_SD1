#include "thread.h"
#include <iostream>

__BEGIN_API

Thread * Thread::_running = nullptr;
unsigned int Thread::_thread_count = 0;
int Thread::_exit_code = 0;
Thread Thread::_main;
CPU::Context Thread::_main_context;
Thread Thread::_dispatcher;
Thread::Ready_Queue Thread::_ready;

int Thread::switch_context(Thread * prev, Thread * next) {
    db<Thread>(TRC) << "Switching context from thread " << prev->id() <<
                        " to thread " << next->id() << ".\n";
    Thread::_running = next;
    CPU::switch_context(prev->context(), next->context());
    return 0;
}

void Thread::thread_exit(int exit_code) {
    db<Thread>(TRC) << "Thread::thread_exit(exit_code=" << exit_code << ")\n";
    _state = FINISHING;
    Thread::_thread_count--;
    Thread::_exit_code = exit_code;
    Thread::yield();
}

int Thread::id() {
    return _id;
}

void Thread::dispatcher() {
    db<Thread>(TRC) << "Thread dispatcher is scheduling threads...\n";
    // Enquanto existir thread do usuário
    while (Thread::_thread_count > 2) {
        // Escolhe uma próxima thread a ser executada
        Thread * next = Thread::_ready.remove()->object();
        /* Atualiza o status da própria thread dispatcher
           para READY e reinsire a mesma em _ready */
        Thread::_dispatcher._state = READY;
        Thread::_ready.insert_tail(&Thread::_dispatcher._link);
        /* Atualiza o ponteiro _running para apontar
           para a próxima thread a ser executada */
        Thread * prev = Thread::_running;
        Thread::_running = next;
        // Atualiza o estado da próxima thread a ser executada
        next->_state = RUNNING;
        // Troca o contexto entre as duas threads
        Thread::switch_context(prev, next);
        /* Testa se o estado da próxima thread é FINISHING
           e caso afirmativo a remove de _ready */
        if (next->_state == FINISHING)
            Thread::_ready.remove(next);
    }
    // Muda o estado da thread dispatcher para FINISHING
    Thread::_dispatcher._state = FINISHING;
    // Remove a thread dispatcher da fila de prontos
    Thread::_ready.remove(&Thread::_dispatcher);
    // Troca o contexto da thread dispatcher para main
    Thread::switch_context(&Thread::_dispatcher, &Thread::_main);
}

void Thread::init(void (* main)(void *)) {
    db<Thread>(TRC) << "Initializing threads main and dispatcher.\n";
    // Cria a Thread main.
    new (&_main) Thread(main, (void *) "main");
    new (&_main_context) CPU::Context();
    // Cria a fila de prontos.
    new (&_ready) Thread::Ready_Queue();
    // Cria a Thread dispatcher.
    new (&_dispatcher) Thread((void (*) (void *)) &Thread::dispatcher, (void *) NULL);
    // Troca o contexto para a Thread main.
    Thread::_running = &Thread::_main;
    CPU::switch_context(&_main_context, _main.context());
}

void Thread::yield() {
    db<Thread>(TRC) << "Thread " << Thread::_running->id() << " is yielding...\n";
    // Escolhe uma próxima thread a ser executada
    Thread * next = Thread::_ready.remove()->object();
    /* Atualiza a prioridade da tarefa que estava
       sendo executada (aquela que chamou yield) com o
       timestamp atual, a fim de reinserí-la na fila de
       prontos atualizada (cuide de casos especiais, como
       estado ser FINISHING ou Thread main que não devem
       ter suas prioridades alteradas) */
    Thread * prev = Thread::_running;
    if (prev != &Thread::_main && prev->_state != FINISHING)
        prev->_link.rank(std::chrono::duration_cast<std::chrono::microseconds>
            (std::chrono::high_resolution_clock::now().time_since_epoch()).count());
    // Reinsire a thread que estava executando na fila de prontos
    prev->_state = READY;
    if (prev->id() > 0)
        Thread::_ready.insert_tail(&prev->_link);
    // Atualiza o ponteiro _running
    Thread::_running = next;
    // Atualiza o estado da próxima thread a ser executada
    next->_state = RUNNING;
    // Troca o contexto entre as threads
    Thread::switch_context(prev, next);
}

int Thread::join() {}

void Thread::suspend() {}

void Thread::resume() {}

Thread::~Thread() {
    db<Thread>(TRC) << "Thread " << Thread::_running->id() << " destroyed.\n";
    delete context();
}

CPU::Context * Thread::context() {
    return _context;
}

__END_API
