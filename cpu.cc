#include "cpu.h"
#include <iostream>

__BEGIN_API

CPU::Context::Context()
{   
    //adicionar implementacao
}

template<typename ... Tn>
CPU::Context::Context(void (* func)(Tn ...), Tn ... an)
{
    //adicionar implementacao
}

void CPU::Context::save()
{
    //adicionar implementação
}

void CPU::Context::load()
{
    //adicionar implementação
}

CPU::Context::~Context()
{
    //adicionar implementação
}

void CPU::switch_context(Context *from, Context *to)
{
     //implementação do método
}

__END_API
