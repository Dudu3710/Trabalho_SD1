#include "cpu.h"
#include <iostream>

__BEGIN_API

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
