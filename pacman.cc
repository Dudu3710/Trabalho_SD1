#include "pacman.h"
#include <iostream>

__BEGIN_API


Thread * Pacman::pacman_thread;
int Pacman::x_pacman = 0;
int Pacman::y_pacman = 0;
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
        Game::tile tile_pac;
        tile_pac = Game::get_tile(x_pacman,y_pacman);

        move();
        //[13][23]
        printf("PACTILE = %d\n",tile_pac);


        
        contador++;
        pacman_thread->yield();
    }

    pacman_thread->thread_exit(4);



}

void Pacman::move() {
    int i = round(x_pacman/16);
    int j = round(y_pacman/16);
    printf("I = %d\n",i);
    printf("J = %d\n",j);
    if (pac_directions == UP) {
        //Game::tile_pac = Game::get_tile(x_pacman,y_pacman);
        Game::tile up_tile = Game::maze_running[i][j-1];
        printf("UPTILE = %d\n",up_tile);
        if (up_tile != W) {
            y_pacman -= vel;
        }
        
        //printf("CIMAAAAAAA\n");

    }
    else if (pac_directions == LEFT) {
        Game::tile left_tile = Game::maze_running[i+1][j];
        printf("LEFTTILE = %d\n",left_tile);
        if (left_tile != W) {
            x_pacman -= vel;
        }
        //printf("ESQUERDA\n");
    }
    else if (pac_directions == RIGHT) {
        Game::tile right_tile = Game::maze_running[i-1][j];
        printf("RIHTTILE = %d\n",right_tile);
        if (right_tile != W) {
            x_pacman += vel;
        }
        //printf("DIREITAAA\n");
    }
    else if (pac_directions == DOWN) {
        Game::tile down_tile = Game::maze_running[i][j+1];
        printf("DOWNTILE = %d\n",down_tile);
        if (down_tile != W) {
            y_pacman += vel;
        }
        //printf("VAIXOXO\n");   
    }
}

void Pacman::set_direction(int dir){
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