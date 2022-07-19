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
// [15][24]
    Pacman::x_pacman = 208;
    Pacman::y_pacman = 368;
    Pacman::vel = 1;
    pac_directions = UP;
    pac_state = READY;
    // direction_pacman = NIL;
    pacman_thread = new Thread(Pacman::pacman_run);
    //pacman.pacman_run(12, pacman.pacman_thread);
    
}

Pacman::~Pacman() {
    //delete pacman_thread;
}

void Pacman::pacman_run() {


    while(Game::_window->isOpen()){

        //printf("EU ENTREI NO PACMANNN\n");
        //sleep(2);
        //printf("%d\n",x_pacman);
        //Game::tile tile_pac;
        //tile_pac = Game::get_tile(x_pacman,y_pacman);

        move();
        //[23][13]


        
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

    if (tile_pac == 0) {
        y_pacman = y_antigo;
        x_pacman = x_antigo;
    } else {
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