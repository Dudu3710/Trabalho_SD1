#ifndef thread_h
#define thread_h

#include "cpu.h"
#include "traits.h"
#include "debug.h"
#include "list.h"
#include <ctime>
#include <chrono>

__BEGIN_API

class Thread
{
protected:
    typedef CPU::Context Context;

public:
    typedef Ordered_List<Thread> Ready_Queue;

    // Thread State
    enum State {
        RUNNING,
        READY,
        SUSPENDED,
        FINISHING,
        WAITING
    };

    /*
     * Construtor vazio. Necessário para inicialização, mas sem importância para a execução das Threads.
     */
    Thread() { }

    /*
     * Cria uma Thread passando um ponteiro para a função a ser executada
     * e os parâmetros passados para a função, que podem variar.
     * Cria o contexto da Thread.
     * PS: devido ao template, este método deve ser implementado neste mesmo arquivo .h
     */
    template<typename ... Tn>
    Thread(void (* entry)(Tn ...), Tn ... an);

    /*
     * Retorna a Thread que está em execução.
     */
    static Thread * running() { return _running; }

    /*
     * Método para trocar o contexto entre duas thread, a anterior (prev)
     * e a próxima (next).
     * Deve encapsular a chamada para a troca de contexto realizada pela class CPU.
     * Valor de retorno é negativo se houve erro, ou zero.
     */
    static int switch_context(Thread * prev, Thread * next);

    /*
     * Termina a thread.
     * exit_code é o código de término devolvido pela tarefa (ignorar agora, vai ser usado mais tarde).
     * Quando a thread encerra, o controle deve retornar à main.
     */
    void thread_exit (int exit_code);

    /*
     * Retorna o ID da thread.
     */
    int id();

    /*
     * Despachante (dispatcher) de threads.
     * Executa enquanto houverem threads do usuário.
     * Chama o escalonador para definir a próxima tarefa a ser executada.
     */
    static void dispatcher();

    /*
     * Realiza a inicialização da class Thread.
     * Cria as Threads main e dispatcher.
     */
    static void init(void (*main)(void *));

    /*
     * Devolve o processador para a thread dispatcher que irá escolher outra thread pronta
     * para ser executada.
     */
    static void yield();

    /*
     * Suspende a thread em execução até que a thread "alvo" finalize.
     */
    int join();

    /*
     * Suspende a thread até que resume() seja chamado.
     */
    void suspend();

    /*
     * Coloca uma Thread que estava suspensa de volta para a fila de prontos.
     */
    void resume();

    /*
    * Coloca a thread para dormir
    */
    void sleep();
    
    /*
    * Acorda uma thread que estava dormindo
    */
    void wakeup();

    /*
     * Destrutor de uma thread. Realiza todos os procedimentos para manter a consistência da classe.
     */
    ~Thread();

    /*
     * Qualquer outro método que você achar necessário para a solução.
     */
    Context * context();
    Ready_Queue::Element * link();

private:
    unsigned int _id;
    bool _call_join;
    Context * volatile _context;
    static Thread * _running;

    static Thread _main;
    static CPU::Context _main_context;
    static Thread _dispatcher;
    static Ready_Queue _ready;
    static Ready_Queue _suspended;
    Ready_Queue::Element _link;
    volatile State _state;

    /*
     * Qualquer outro atributo que você achar necessário para a solução.
     */
    static unsigned int _thread_count;
    int _exit_code;
};

template<typename ... Tn>
inline Thread::Thread(void (* entry)(Tn ...), Tn ... an)
: _link(this, (std::chrono::duration_cast<std::chrono::microseconds>
    (std::chrono::high_resolution_clock::now().time_since_epoch()).count()))
{
    db<Thread>(TRC) << "Thread " << _thread_count << " created.\n";
    _context = new CPU::Context(entry, an ...);
    _id = Thread::_thread_count++;
    //_exit_code = id - 1;
    if (_id > 0)
        _ready.insert_tail(&_link);
    _state = READY;
}

__END_API

#endif
