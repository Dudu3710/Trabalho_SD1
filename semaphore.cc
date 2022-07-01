#include "semaphore.h"
#include <iostream>

__BEGIN_API

void Semaphore::p() {
    if (fdec(valor) < 0) {
        sleep();
    }
}

void Semaphore::v() {

    if (finc(valor) < 1) {
        wakeup();
    }
}

int Semaphore::finc(volatile int & number) {
    return CPU::finc(number);
}

int Semaphore::fdec(volatile int & number) {
    return CPU::fdec(number);
}

void Semaphore::sleep() {
    Thread * atual = Thread::running();
    _waiting.insert_tail(atual->link());
    atual->sleep();
}

void Semaphore::wakeup() {
    Thread * acordada = _waiting.remove()->object();
    acordada->wakeup();
}

void Semaphore::wakeup_all() {
    Thread * acordada;
    while (_waiting.size() > 0) {
        acordada = _waiting.remove()->object();
        acordada->wakeup();
    }
}

__END_API
