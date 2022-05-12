#include "thread.h"
#include <iostream>

__BEGIN_API

Thread* Thread::_running = nullptr;

int Thread::switch_context(Thread * prev, Thread * next) 
{       
    if (CPU::switch_context(prev->context(),next->context()) == -1) {
        return -1;
    }
    _running = next;
    return 0;
}

void Thread::thread_exit (int exit_code) 
{
    delete context();
}

int Thread::id()
{
    return _id;
}

CPU::Context* Thread::context()
{
    return _context;
}



__END_API