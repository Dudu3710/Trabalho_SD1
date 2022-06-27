#include "semaphore.h"
#include <iostream>

__BEGIN_API

void Semaphore::p() {
    if (valor > 0) {
        valor = fdec(valor);
        return;
    } else {
        sleep();
    }
}

void Semaphore::v() {
    if (valor == 0) {
        valor = finc(valor);
        wakeup();
        return;
    } else {
        valor = finc(valor);
    }
}

int Semaphore::finc(volatile int & number) {
    return CPU::finc(number);
}

int Semaphore::fdec(volatile int & number) {
    return CPU::fdec(number);
}

void Semaphore::sleep() {
    Thread::sleep();
}

void Semaphore::wakeup() {
    Thread::wakeup();
}

void Semaphore::wakeup_all() {
    Thread::wakeup_all();
}

__END_API
