#include "timer.h"
#include <iostream>

__BEGIN_API

Timer::Timer(const unsigned int period, const Function * handler) {
    db<Timer>(TRC) << "Inicializador timer.\n";
    action.sa_handler = handler;
    sigaction(SIGALRM,&action, NULL);
    timer.it_value.tv_sec = 0;
    timer.it_value.tv_usec = _period;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = _period;
    setitimer(ITIMER_REAL,&timer,NULL);
}

void Timer::reset() {
    db<Timer>(TRC) << "Resetor timer.\n";
    timer.it_value.tv_sec = 0;
    timer.it_value.tv_usec = _period;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = _period;
    setitimer(ITIMER_REAL,&timer,NULL);
}

__END_API