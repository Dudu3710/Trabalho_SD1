#include "game.h"

__BEGIN_API

// Pacman* Game::_pacman = nullptr;
// Ghost* Game::ghost_b = nullptr;
// Ghost* Game::ghost_p = nullptr;
// Ghost* Game::ghost_r = nullptr;
// Ghost* Game::ghost_y = nullptr;
// Draw* Game::_drawing = nullptr;
// sf::RenderWindow* _window;
// Semaphore* Game::_semaphore = nullptr;
// Thread* Game::pacman_thread = nullptr;
// Thread* Game::ghost_thread_b = nullptr;
// Thread* Game::ghost_thread_p = nullptr;
// Thread* Game::ghost_thread_r = nullptr;
// Thread* Game::ghost_thread_y = nullptr;
// Thread* Game::_drawing_thread = nullptr;
// Thread* Game::_input_thread = nullptr;

Pacman * Game::_pacman;
Ghost * Game::ghost_b;
Ghost * Game::ghost_p;
Ghost * Game::ghost_r;
Ghost * Game::ghost_y;
Draw * Game::_drawing;
sf::RenderWindow * Game::_window;
Semaphore Game::_semaphore;
//Thread* Game::pacman_thread;
Thread* Game::ghost_thread_b;
Thread* Game::ghost_thread_p;
Thread* Game::ghost_thread_r;
Thread* Game::ghost_thread_y;
// Thread* Game::_drawing_thread;
Thread* Game::_input;
 //Thread* Game::_input_thread = null


Game::Game() {

    
    sf::RenderWindow window (sf::VideoMode(448, 496), "Pacman");
    
    window.setKeyRepeatEnabled(false);
    window.setFramerateLimit(30);

    _window = &window;

    //_input = new Thread(input_handler, &window);


    _pacman = new Pacman();
    // ghost_b = new Ghost(0, 190, 150);
    // ghost_p = new Ghost(1, 195, 150);
    // ghost_r = new Ghost(2, 200, 150);
    // ghost_y = new Ghost(3, 205, 150);

    _input = new Thread(input_handler, &window);

    // pacman_thread = new Thread(criar_pacman);
    ghost_thread_b = new Thread(criar_ghost,0);
    ghost_thread_p = new Thread(criar_ghost,1);
    ghost_thread_r = new Thread(criar_ghost,2);
    ghost_thread_y = new Thread(criar_ghost,3);
    // _drawing_thread = new Thread(desenhar);
    // //_input_thread = new Thread(ler_input);

    _drawing = new Draw();

    //Pacman *_pacman = new Pacman(200, 300);

    //Ghost *_ghost[4] = {new Ghost(0,190,150),new Ghost(1,195,150),new Ghost(2,200,150),new Ghost(3,205,150)};
    //_drawing = new Draw();
    //&_semaphore = new Semaphore();

        
    // _window.clear();
    // _window.draw(maze_sprite);
    // pac_0_sprite.setPosition(220, 365);
    // _window.draw(pac_0_sprite);
    // ghost_r_0_sprite.setPosition(245, 150);
    // _window.draw(ghost_r_0_sprite);
    // _window.display();
    _drawing->_draw->join();
    _input->join();
    _pacman->pacman_thread->join();
    ghost_thread_b->join();
    ghost_thread_p->join();
    ghost_thread_r->join();
    ghost_thread_y->join();



    // delete _semaphore;
    // delete pacman_thread;
    // delete ghost_thread_b;
    // delete ghost_thread_p;
    // delete ghost_thread_r;
    // delete ghost_thread_y;
    // delete _drawing_thread;
    // delete _input_thread;


    }

void Game::input_handler(sf::RenderWindow * _window){
    while (_window->isOpen())
    {   
        //printf("ESTOU na maIN\n");
        //sleep(2);
        sf::Event event;
        while (_window->pollEvent(event))
        {
            switch (event.type) {
            case sf::Event::Closed:
                 _window->close();
                 break;

            
            // key pressed
            case sf::Event::KeyPressed:
                _semaphore.p();
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    std::cout << "Keyboard esquerda!" << std::endl;
                    _pacman->set_direction(0);
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    std::cout << "Keyboard direita!" << std::endl;
                    _pacman->set_direction(1);
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                    std::cout << "Keyboard para baixo!" << std::endl;
                    _pacman->set_direction(2);
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    std::cout << "Keyboard para cima!" << std::endl;
                    _pacman->set_direction(3);
                } else
                    std::cout << "Keyboard pressed = " << event.key.code << std::endl;
                break;
            
            }
            _semaphore.v();
            //_input->yield();
        }
        _input->yield();
        
        _window->clear();
}
    _input->thread_exit(8);
}

Game::tile Game::get_tile(int x, int y) {
    int i = round(y/16);
    int j = round(x/16);

    return maze_running[i][j];
}

// void Game::criar_pacman() {
//     while (_window.isOpen()){
//         _semaphore.p();
//         _pacman->pacman_run();
//         _semaphore.v();
//     }
//     pacman_thread->thread_exit(1);
// }

void Game::criar_ghost(int cor) {

    switch (cor)
    {
    case (0):
        ghost_b = new Ghost(0, 190, 150);
        while (_window->isOpen()){
            ghost_b->ghost_run(cor);
            ghost_thread_b->yield();
        }
        ghost_thread_b->thread_exit(9);
        break;
    case (1):
        ghost_p = new Ghost(1, 195, 150);
        while (_window->isOpen()){
            ghost_p->ghost_run(cor);
            ghost_thread_p ->yield();
        }
        ghost_thread_p->thread_exit(10);
        break;
    case (2):
        ghost_r = new Ghost(2, 200, 150);
        while (_window->isOpen()){
            ghost_r->ghost_run(cor);
            ghost_thread_r ->yield();
        }
        ghost_thread_r->thread_exit(11);
        break;
    case (3):
        ghost_y = new Ghost(3, 205, 150);
        while (_window->isOpen()){
            ghost_y->ghost_run(cor);
            ghost_thread_y->yield();
        }
        ghost_thread_y->thread_exit(12);
        break;
    default:
        break;
    }

}

// void Game::desenhar() {

// }

// void Game::ler_input() {

// }









__END_API