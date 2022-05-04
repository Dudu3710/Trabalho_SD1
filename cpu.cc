#include "cpu.h"
#include <iostream>

__BEGIN_API

/*CPU::Context::Context()
{   
    if (getcontext(&_context) == 0) {
        printf("ok");
    } else {
        printf("problemao");
    };
    //adicionar implementacao
    //_context.uc_link = 0;
    //_context.uc_stack.ss_sp = malloc(STACK_SIZE);
    //_stack = ??
    //_context.uc_stack.ss_size = STACK_SIZE;
    //_context.uc_stack.ss_flags = 0;
    //makecontext(&_context,(void*)&Main,0); make context??
}*/

template<typename ... Tn>
CPU::Context::Context(void (* func)(Tn ...), Tn ... an)
{
    //adicionar implementacao
    //_context.save();
    getcontext(&_context);
    _stack = malloc(STACK_SIZE);
    _context.uc_link = 0;
    _context.uc_stack.ss_sp = malloc(STACK_SIZE);
    _context.uc_stack.ss_size = STACK_SIZE;
    _context.uc_stack.ss_flags = 0;
    makecontext(&_context, func, (int)sizeof...(an), an...);
}

void CPU::Context::save()
{
    //adicionar implementação
    getcontext(&_context);

}

void CPU::Context::load()
{
    //adicionar implementação
    setcontext(&_context);
}

CPU::Context::~Context()
{
    //adicionar implementação
    free(_context.uc_stack.ss_sp);
}

void CPU::switch_context(Context *from, Context *to)
{
     //implementação do método

    swapcontext(&from->_context, &to->_context);
}

__END_API
