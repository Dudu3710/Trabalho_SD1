#include "pacman.h"
#include <iostream>

__BEGIN_API


Thread * Pacman::pacman_thread;
int Pacman::x_pacman = 0;
int Pacman::y_pacman = 0;
int Pacman::x_antigo = 0;
int Pacman::y_antigo = 0;
int Pacman::contador_princ = 0;
int Pacman::contador = 0;
int Pacman::vel = 0;
Pacman::directions pac_directions;
Pacman::state pac_state;

Pacman::Pacman() {;
    Pacman::x_pacman = 208;
    Pacman::y_pacman = 368;
    Pacman::vel = 2;
    pac_directions = UP;
    pac_state = READY;
    pacman_thread = new Thread(Pacman::pacman_run);
}

Pacman::~Pacman() {
    //delete pacman_thread;
}

void Pacman::pacman_run() {


    while(Game::_window->isOpen()){
        move();
        
        contador_princ++;
        if (contador_princ % 5 == 0){
            contador++;
        }
        pacman_thread->yield();
    }

    pacman_thread->thread_exit(4);

}

void Pacman::move() {
    int i = round((y_pacman+7)/16);
    int j = round((x_pacman+7)/16);
    Game::tile tile_pac = Game::maze_running[i][j];
    // printf("PACTILE = %d\n",tile_pac);
    // printf("I = %d\n",i);
    // printf("J = %d\n",j);

    if (tile_pac == 0 || tile_pac == 1) {  // walls or prison gates
        y_pacman = y_antigo;
        x_pacman = x_antigo;
    } else {
        if (tile_pac == 2) {  // portals
            if (x_pacman < 16) {
                x_pacman = 432;
            } else if (x_pacman > 432) {
                x_pacman = 16;
            }
        }
        x_antigo = x_pacman;
        y_antigo = y_pacman;
        if (pac_directions == UP) {
            y_pacman -= vel;
        } else if (pac_directions == LEFT) {
            x_pacman -= vel;
        } else if (pac_directions == RIGHT) {
            x_pacman += vel;
        } else if (pac_directions == DOWN) {
            y_pacman += vel;
        }
    }

    // Atualizar Pontos
    if (tile_pac == 4) {
        Game::maze_running[i][j] = Game::e;
    }

    if (tile_pac == 6) {
        Game::maze_running[i][j] = Game::E;
    }

}

void Pacman::set_direction(int dir) {
    if (dir == 0) {
        pac_directions = LEFT;
    }
    else if (dir == 1) {
        pac_directions = RIGHT;
    }
    else if (dir == 2) {
        pac_directions = DOWN;
    }
    else if (dir == 3) {
        pac_directions = UP;
    }
}


__END_API