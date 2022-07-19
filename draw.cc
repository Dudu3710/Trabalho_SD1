#include "draw.h"

__BEGIN_API


Thread* Draw::_draw;
//sf::RenderWindow * Game::_window;
sf::Sprite Draw::pac_0_sprites;
sf::Sprite Draw::pac_1_sprites;
sf::Sprite Draw::pac_2_sprites;
sf::Sprite Draw::ghost_r_0_sprites;
sf::Sprite Draw::ghost_r_1_sprites;
sf::Sprite Draw::ghost_p_0_sprites;
sf::Sprite Draw::ghost_p_1_sprites;
sf::Sprite Draw::ghost_b_0_sprites;
sf::Sprite Draw::ghost_b_1_sprites;
sf::Sprite Draw::ghost_y_0_sprites;
sf::Sprite Draw::ghost_y_1_sprites;
sf::Sprite Draw::maze_sprites;
sf::Sprite Draw::pill_sprites;
sf::Sprite Draw::bigpill_sprites;

Draw::Draw() {
    _draw = new Thread(Draw::draw_run);
    //load bin and textures
    load_and_bind_textures();
}

void Draw::draw_run(){
    while(Game::_window->isOpen()){
        //printf("ENTREI DRAW\n");
        //sleep(2);
        Game::_window->clear();
        Game::_window->draw(maze_sprites);

        draw_pacman();
        draw_ghosts();
        //pac_0_sprites.setPosition(Pacman::x_pacman, Pacman::y_pacman);
        //Game::_window->draw(pac_0_sprites);

        read_maze_and_draw();
        Game::maze_running;

        Game::_window->display();
        //printf("SAI DO DEAW");
        _draw->yield();
    }
    _draw->thread_exit(7);
}

void Draw::read_maze_and_draw() {
    for (int i = 0 ; i < 31; i++) {
        for (int j = 0; j < 28 ; j++) {
            if (Game::maze_running[i][j] == W) {
                
            } 
            if (Game::maze_running[i][j] == O) {
                bigpill_sprites.setPosition(j*16,i*16);
                Game::_window->draw(bigpill_sprites);
            }
            if (Game::maze_running[i][j] == o) {
                pill_sprites.setPosition(j*16,i*16);
                Game::_window->draw(pill_sprites);
            }
            
        }
    }

}
void Draw::draw_pacman(){
    if (Pacman::contador %3 == 0) {
        pac_0_sprites.setPosition(Pacman::x_pacman, Pacman::y_pacman);
        Game::_window->draw(pac_0_sprites);     
    }
    else if (Pacman::contador %3 == 1) {
        pac_1_sprites.setPosition(Pacman::x_pacman, Pacman::y_pacman);
        Game::_window->draw(pac_1_sprites);     
    }
    else {
        pac_2_sprites.setPosition(Pacman::x_pacman, Pacman::y_pacman);
        Game::_window->draw(pac_2_sprites);     
    }
}

void Draw::draw_ghosts() {
    ghost_b_0_sprites.setPosition(Game::ghost_b->x_ghost, Game::ghost_b->y_ghost);
    Game::_window->draw(ghost_b_0_sprites);

    ghost_p_0_sprites.setPosition(Game::ghost_p->x_ghost, Game::ghost_p->y_ghost);
    Game::_window->draw(ghost_p_0_sprites);

    ghost_r_0_sprites.setPosition(Game::ghost_r->x_ghost, Game::ghost_r->y_ghost);
    Game::_window->draw(ghost_r_0_sprites);

    ghost_y_0_sprites.setPosition(Game::ghost_y->x_ghost, Game::ghost_y->y_ghost);
    Game::_window->draw(ghost_y_0_sprites);
}

void Draw::load_and_bind_textures()
{
    // Bind map textures    
    
    maze_tex.loadFromFile("sprites/maze/maze.png");
    maze_sprites.setTexture(maze_tex);
    maze_sprites.scale(2, 2);
    pill_tex.loadFromFile("sprites/maze/p-0.png");
    pill_sprites.setTexture(pill_tex);
    bigPill_tex.loadFromFile("sprites/maze/p-1.png");
    bigpill_sprites.setTexture(bigPill_tex);

    // Bind Pacman textures
    pac_0_tex.loadFromFile("sprites/pacman/0.png");
    pac_0_sprites.setTexture(pac_0_tex);
    pac_1_tex.loadFromFile("sprites/pacman/1.png");
    pac_1_sprites.setTexture(pac_1_tex);
    pac_2_tex.loadFromFile("sprites/pacman/2.png");
    pac_2_sprites.setTexture(pac_2_tex);
    dead_0_tex.loadFromFile("sprites/pacman/d-0.png");
    dead_0_sprite.setTexture(dead_0_tex);
    dead_1_tex.loadFromFile("sprites/pacman/d-1.png");
    dead_1_sprite.setTexture(dead_1_tex);
    dead_2_tex.loadFromFile("sprites/pacman/d-2.png");
    dead_2_sprite.setTexture(dead_2_tex);
    dead_3_tex.loadFromFile("sprites/pacman/d-3.png");
    dead_3_sprite.setTexture(dead_3_tex);
    dead_4_tex.loadFromFile("sprites/pacman/d-4.png");
    dead_4_sprite.setTexture(dead_4_tex);
    dead_5_tex.loadFromFile("sprites/pacman/d-5.png");
    dead_5_sprite.setTexture(dead_5_tex);
    dead_6_tex.loadFromFile("sprites/pacman/d-6.png");
    dead_6_sprite.setTexture(dead_6_tex);
    dead_7_tex.loadFromFile("sprites/pacman/d-7.png");
    dead_7_sprite.setTexture(dead_7_tex);
    dead_8_tex.loadFromFile("sprites/pacman/d-8.png");
    dead_8_sprite.setTexture(dead_8_tex);
    dead_9_tex.loadFromFile("sprites/pacman/d-9.png");
    dead_9_sprite.setTexture(dead_9_tex);
    dead_10_tex.loadFromFile("sprites/pacman/d-10.png");
    dead_10_sprite.setTexture(dead_10_tex);

    // Bind ghost textures
    ghost_r_0_tex.loadFromFile("sprites/ghosts/r-0.png");
    ghost_r_0_sprites.setTexture(ghost_r_0_tex);
    ghost_r_1_tex.loadFromFile("sprites/ghosts/r-1.png");
    ghost_r_1_sprites.setTexture(ghost_r_1_tex);
    ghost_p_0_tex.loadFromFile("sprites/ghosts/p-0.png");
    ghost_p_0_sprites.setTexture(ghost_p_0_tex);
    ghost_p_1_tex.loadFromFile("sprites/ghosts/p-1.png");
    ghost_p_1_sprites.setTexture(ghost_p_1_tex);
    ghost_b_0_tex.loadFromFile("sprites/ghosts/b-0.png");
    ghost_b_0_sprites.setTexture(ghost_b_0_tex);
    ghost_b_1_tex.loadFromFile("sprites/ghosts/b-1.png");
    ghost_b_1_sprites.setTexture(ghost_b_1_tex);
    ghost_y_0_tex.loadFromFile("sprites/ghosts/y-0.png");
    ghost_y_0_sprites.setTexture(ghost_y_0_tex);
    ghost_y_1_tex.loadFromFile("sprites/ghosts/y-1.png");
    ghost_y_1_sprites.setTexture(ghost_y_1_tex);
    ghost_scared_0_tex.loadFromFile("sprites/ghosts/s-0.png");
    ghost_scared_0_sprite.setTexture(ghost_scared_0_tex);
    ghost_scared_1_tex.loadFromFile("sprites/ghosts/s-1.png");
    ghost_scared_1_sprite.setTexture(ghost_scared_1_tex);
    ghost_scared_2_tex.loadFromFile("sprites/ghosts/s-2.png");
    ghost_scared_2_sprite.setTexture(ghost_scared_2_tex);
    ghost_scared_3_tex.loadFromFile("sprites/ghosts/s-3.png");
    ghost_scared_3_sprite.setTexture(ghost_scared_3_tex);

     // Bind ghost eye textures
    eye_up_tex.loadFromFile("sprites/eyes/up.png");
    eye_up_sprite.setTexture(eye_up_tex);
    eye_right_tex.loadFromFile("sprites/eyes/right.png");
    eye_right_sprite.setTexture(eye_right_tex);
    eye_down_tex.loadFromFile("sprites/eyes/down.png");
    eye_down_sprite.setTexture(eye_down_tex);
    eye_left_tex.loadFromFile("sprites/eyes/left.png");
    eye_left_sprite.setTexture(eye_left_tex);

    // Bind UI textures
    num_0_tex.loadFromFile("sprites/ui/0.png");
    num_0_sprite.setTexture(num_0_tex);
    num_1_tex.loadFromFile("sprites/ui/1.png");
    num_1_sprite.setTexture(num_1_tex);
    num_2_tex.loadFromFile("sprites/ui/2.png");
    num_2_sprite.setTexture(num_2_tex);
    num_3_tex.loadFromFile("sprites/ui/3.png");
    num_3_sprite.setTexture(num_3_tex);
    num_4_tex.loadFromFile("sprites/ui/4.png");
    num_4_sprite.setTexture(num_4_tex);
    num_5_tex.loadFromFile("sprites/ui/5.png");
    num_5_sprite.setTexture(num_5_tex);
    num_6_tex.loadFromFile("sprites/ui/6.png");
    num_6_sprite.setTexture(num_6_tex);
    num_7_tex.loadFromFile("sprites/ui/7.png");
    num_7_sprite.setTexture(num_7_tex);
    num_8_tex.loadFromFile("sprites/ui/8.png");
    num_8_sprite.setTexture(num_8_tex);
    num_9_tex.loadFromFile("sprites/ui/9.png");
    num_9_sprite.setTexture(num_9_tex);
    score_200_tex.loadFromFile("sprites/ui/200.png");
    score_200_sprite.setTexture(score_200_tex);
    score_400_tex.loadFromFile("sprites/ui/400.png");
    score_400_sprite.setTexture(score_400_tex);
    score_800_tex.loadFromFile("sprites/ui/800.png");
    score_800_sprite.setTexture(score_800_tex);
    score_1600_tex.loadFromFile("sprites/ui/1600.png");
    score_1600_sprite.setTexture(score_1600_tex);
    ready_tex.loadFromFile("sprites/ui/ready.png");
    ready_sprite.setTexture(ready_tex);
    gameover_tex.loadFromFile("sprites/ui/gameover.png");
    gameover_sprite.setTexture(gameover_tex);
    life_tex.loadFromFile("sprites/ui/life.png");
    life_sprite.setTexture(life_tex);
    score_tex.loadFromFile("sprites/ui/score_tex.png");
    score_sprite.setTexture(score_tex);
    high_tex.loadFromFile("sprites/ui/high.png");
    high_sprite.setTexture(high_tex);
    score_100_tex.loadFromFile("sprites/ui/100.png");
    score_100_sprite.setTexture(score_100_tex);
    score_300_tex.loadFromFile("sprites/ui/300.png");
    score_300_sprite.setTexture(score_300_tex);

    // Fruit textures
    cherry_tex.loadFromFile("sprites/fruits/cherry.png");
    cherry_sprite.setTexture(cherry_tex);
    strawberry_tex.loadFromFile("sprites/fruits/strawberry.png");
    strawberry_sprite.setTexture(strawberry_tex);
}


__END_API