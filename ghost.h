#ifndef ghost_h
#define ghost_h

#include <iostream>
#include "traits.h"
#include "thread.h"
#include "cpu.h"
#include "game.h"

__BEGIN_API

class Ghost 
{

public:

    typedef enum {LEFT, UP, RIGHT, DOWN, NIL} directions;
    typedef enum {READY, RUNNING, FINISHING, PAUSED} state;
    typedef enum {FOLLOWING, IDLE} combat;

    Ghost() { };
    // int para definir as cores!!
    // blue = 0
    // pink = 1
    // red = 2
    // yellow = 3
    Ghost(int cor, int x, int y);

    ~Ghost();
    static void join(){ if(ghost_thread){ ghost_thread->join();}} 

    static void ghost_run(int cor);

    int cor_ghost;
    int x_ghost;
    int y_ghost;

    bool window_open;

    combat combat_ghost;
    state state_ghost;
    directions direction_ghost;

    static Thread *ghost_thread;



protected:






private:



};











__END_API




#endif