#include "ghost.h"

__BEGIN_API

//Thread * Ghost::ghost_thread;

Ghost::Ghost(int cor, int x, int y) {
    cor_ghost = cor;
    x_ghost = x;
    y_ghost = y;
    vel = 1;
    //window_open = true;
    state_ghost = READY;
    ghost_direction = UP;
    //ghost_thread = new Thread(ghost_run, cor);
    //ghost_run(cor, ghost_thread);
};

Ghost::~Ghost() {
    //delete this->ghost_thread;
}

void Ghost::ghost_run(int cor) {

    run();
    //Draw::draw_ghosts(cor_ghost, x_ghost, y_ghost);
    //printf("GHOST COR %d PORRA\n",cor);

};

void Ghost::run() {
    int i = round((y_ghost+7)/16);
    int j = round((x_ghost+7)/16);
    Game::tile tile_ghost = Game::maze_running[i][j];
    printf("GHOST%dTILE = %d\n",cor_ghost,tile_ghost);
    printf("I = %d\n",i);
    printf("J = %d\n",j);

    if (tile_ghost == 0) {
        y_ghost = y_antigo;
        x_ghost = x_antigo;
        // Change ghost_direction clockwise
        if (ghost_direction == UP) {
            ghost_direction = RIGHT;
        } else if (ghost_direction == RIGHT) {
            ghost_direction = DOWN;
        } else if (ghost_direction == DOWN) {
            ghost_direction = LEFT;
        } else if (ghost_direction == LEFT) {
            ghost_direction = UP;
        }

        // aaaaaaaaaaAAAaaAAAaAAAaaAAAAAA
        // if (ghost_direction == UP || ghost_direction == DOWN) {
        //     Game::tile tile_right = Game::maze_running[i+1][j];
        //     Game::tile tile_left = Game::maze_running[i-1][j];
        //     if (tile_right != 0) {  // Try to go RIGHT
        //         ghost_direction = RIGHT;
        //     } else if (tile_left != 0) {  // Try to go LEFT
        //         ghost_direction = LEFT;
        //     }
        // } else if (ghost_direction == RIGHT || ghost_direction == LEFT) {
        //     Game::tile tile_up = Game::maze_running[i][j-1];
        //     Game::tile tile_down = Game::maze_running[i][j+1];
        //     if (tile_down != 0) {  // Try to go DOWN
        //         ghost_direction = DOWN;
        //     } else if (tile_up != 0) {  // Try to go UP
        //         ghost_direction = UP;
        //     }
        // }

        // Randomized change to ghost_direction
        // std::random_device seed;
        // std::mt19937 gen{seed()}; // seed the generator
        // std::uniform_int_distribution dist{0, 3}; // set min and max
        // ghost_direction = dist(gen);
    } else {
        x_antigo = x_ghost;
        y_antigo = y_ghost;
        if (ghost_direction == UP) {
            y_ghost -= vel;
        } else if (ghost_direction == LEFT) {
            x_ghost -= vel;
        } else if (ghost_direction == RIGHT) {
            x_ghost += vel;
        } else if (ghost_direction == DOWN) {
            y_ghost += vel;
        }
    }
}



__END_API
