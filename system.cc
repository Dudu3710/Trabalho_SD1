#include "system.h"
#include "thread.h"
#include <iostream>

__BEGIN_API

void System::init(void (* main)(void *)) {
    db<System>(TRC) << "System is calling Thread::init(main)\n";
    setvbuf(stdout, 0, _IONBF, 0);
    Thread::init(main);
}

__END_API
