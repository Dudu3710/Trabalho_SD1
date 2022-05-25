#include "thread.h"
#include <iostream>

__BEGIN_API

Thread* Thread::_running = nullptr;
unsigned int Thread::_thread_count = 0;
Ready_Queue Thread::_ready = new Ordered_List<Thread>();

int Thread::switch_context(Thread * prev, Thread * next)
{
    db<Thread>(TRC) << "Switching context from Thread " << prev->id() <<
                        " to Thread " << next->id() << ".\n";
    prev->_state = READY;
    _running = next;
    next->_state = RUNNING;
    CPU::switch_context(prev->context(), next->context());
    return 0;
}

void Thread::thread_exit(int exit_code)
{
    db<Thread>(TRC) << "Thread::thread_exit(exit_code=" << exit_code << ")\n";
    _state = FINISHING;
    delete context();
    Thread::_thread_count--;
}

int Thread::id()
{
    return _id;
}

void Thread::dispatcher() {
    // TODO: imprimir informação usando o debug em nível TRC
    // db<Thread>(TRC) << "TODO...";
}

void Thread::init(void (* main)(void *)) {
    db<Thread>(TRC) << "Initializing Threads main and dispatcher.\n";
    // Cria a Thread main.
    _main = new Thread(main);
    _main_context = _main->context();
    // Cria a Thread dispatcher.
    _dispatcher = new Thread();
    // Troca o contexto para a Thread main.
    _main_context->load();
}

void Thread::yield() {
    // TODO: imprimir informação usando o debug em nível TRC
    // db<Thread>(TRC) << "TODO...";
}

Thread::~Thread() {
    // TODO: imprimir informação usando o debug em nível TRC
    // db<Thread>(TRC) << "TODO...";
}

CPU::Context* Thread::context()
{
    return _context;
}

__END_API
