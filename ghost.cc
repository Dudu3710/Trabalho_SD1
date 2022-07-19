#include "ghost.h"

__BEGIN_API

//Thread * Ghost::ghost_thread;

Ghost::Ghost(int cor, int x, int y) {
    cor_ghost = cor;
    x_ghost = x;
    y_ghost = y;
    //window_open = true;
    state_ghost = READY;
    direction_ghost = DOWN;
    //ghost_thread = new Thread(ghost_run, cor);
    //ghost_run(cor, ghost_thread);
};

Ghost::~Ghost() {
    //delete this->ghost_thread;
}

void Ghost::ghost_run(int cor) {

    run();
    //Draw::draw_ghosts(cor_ghost, x_ghost, y_ghost);
    printf("GHOST COR %d PORRA\n",cor);

};

void Ghost::run() {

}



__END_API
