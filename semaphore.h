#ifndef semaphore_h
#define semaphore_h

#include "cpu.h"
#include "thread.h"
#include "traits.h"
#include "debug.h"
#include "list.h"

__BEGIN_API

class Semaphore
{
public:
    typedef Ordered_List<Thread> Waiting_Queue;

    Semaphore() {
        valor = 1;
        new (&_waiting) Waiting_Queue();
    };
    ~Semaphore() {
        wakeup_all();
        delete this;
    };

    void p();
    
    void v();

private:
    // Atomic operations
    int finc(volatile int & number);
    int fdec(volatile int & number);

    // Thread operations
    void sleep();
    void wakeup();
    void wakeup_all();

private:
    int valor;
    //DECLARAÇÃO DOS ATRIBUTOS DO SEMÁFORO
    Waiting_Queue _waiting;
};

__END_API

#endif

