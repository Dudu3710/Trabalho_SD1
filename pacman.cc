#include "pacman.h"
#include <iostream>

__BEGIN_API


Thread * Pacman::pacman_thread;
int Pacman::x_pacman = 0;
int Pacman::y_pacman = 0;

Pacman::Pacman() {;
    Pacman::x_pacman = 200;
    Pacman::y_pacman = 150;
    // direction_pacman = NIL;
    pacman_thread = new Thread(Pacman::pacman_run);
    //pacman.pacman_run(12, pacman.pacman_thread);
    
}

Pacman::~Pacman() {
    //delete pacman_thread;
}

void Pacman::pacman_run() {


    while(Game::_window->isOpen()){

        printf("EU ENTREI NO PACMANNN\n");

        pacman_thread->yield();
    }

    pacman_thread->thread_exit(4);



}


__END_API