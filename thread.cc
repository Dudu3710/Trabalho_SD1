#include "thread.h"
#include <iostream>

__BEGIN_API

Thread * Thread::running() 
{
    // implementar
}

int Thread::switch_context(Thread * prev, Thread * next) 
{
    // implementar
}

void Thread::thread_exit (int exit_code) 
{
    // implementar
}

int Thread::id()
{
    // implementar
}


__END_API