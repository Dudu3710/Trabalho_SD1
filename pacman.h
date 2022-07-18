#ifndef pacman_h
#define pacman_h
#include <iostream>
#include "traits.h"
#include "thread.h"
#include "cpu.h"
#include "game.h"

__BEGIN_API

class Pacman 
{

public:
    typedef enum {W, G, P, u, o, e, O, E, F} tile;
    typedef enum {LEFT, UP, RIGHT, DOWN, NIL} directions;
    typedef enum {READY, RUNNING, FINISHING, PAUSED} state;

    Pacman();
    ~Pacman();   
 

    static void pacman_run();

    static int x_pacman;
    static int y_pacman;

    bool window_open;

    state state_pacman;
    directions direction_pacman;

    static Thread *pacman_thread;


    static void join(){ if(pacman_thread){ pacman_thread->join();}}   


protected:





private:
    //Thread *pacman_thread;
    
    








};






__END_API





#endif