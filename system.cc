#include "system.h"
#include "thread.h"
#include <iostream>

__BEGIN_API

void System::init()
{
    setvbuf (stdout, 0, _IONBF, 0);
}

void System::init(void (* main)(void *)) {
    Thread::init(main);
}

__END_API
