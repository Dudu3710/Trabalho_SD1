#include "ghost.h"

__BEGIN_API

Thread * Ghost::ghost_thread;

Ghost::Ghost(int cor, int x, int y) {
    cor_ghost = cor;
    x_ghost = x;
    y_ghost = y;
    window_open = true;
    state_ghost = READY;
    direction_ghost = NIL;
    ghost_thread = new Thread(ghost_run, cor);
    //ghost_run(cor, ghost_thread);
};

Ghost::~Ghost() {
    //delete this->ghost_thread;
}

void Ghost::ghost_run(int cor) {

    while(Game::_window->isOpen()){

        printf("GOHOST\n");
        ghost_thread->yield();
    }
    ghost_thread->thread_exit(5);

};



__END_API
