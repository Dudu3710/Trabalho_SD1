#ifndef timer_h
#define timer_h

#include "traits.h"
#include "debug.h"
#include "signal.h"
#include "sys/time.h"

__BEGIN_API

class Timer 
{

public:

    typedef void (Function) (int);

    Timer() {
    };

    Timer(const unsigned int period, const Function * handler);
        
    void reset();

private:

    struct sigaction action;
    struct itimerval timer;
    unsigned int _period;
    int *handler;
    static const unsigned int q_timer = Traits<Timer>::q_timer;
};

__END_API

#endif