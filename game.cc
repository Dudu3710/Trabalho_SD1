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
// Thread* Game::pacman_thread;
// Thread* Game::ghost_thread_b;
// Thread* Game::ghost_thread_p;
// Thread* Game::ghost_thread_r;
// Thread* Game::ghost_thread_y;
// Thread* Game::_drawing_thread;
Thread* Game::_input;
 //Thread* Game::_input_thread = null


Game::Game() {

    
    sf::RenderWindow window (sf::VideoMode(450, 500), "Pacman");
    window.setKeyRepeatEnabled(false);
    window.setFramerateLimit(30);

    _window = &window;

    //_input = new Thread(input_handler, &window);


    _pacman = new Pacman();
    ghost_b = new Ghost(0, 190, 150);
    ghost_p = new Ghost(1, 195, 150);
    ghost_r = new Ghost(2, 200, 150);
    ghost_y = new Ghost(3, 205, 150);
    _drawing = new Draw();

    _input = new Thread(input_handler, &window);

    // pacman_thread = new Thread(criar_pacman);
    // ghost_thread_b = new Thread(criar_ghost,0);
    // ghost_thread_p = new Thread(criar_ghost,1);
    // ghost_thread_r = new Thread(criar_ghost,2);
    // ghost_thread_y = new Thread(criar_ghost,3);
    // _drawing_thread = new Thread(desenhar);
    // //_input_thread = new Thread(ler_input);


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
    
    _input->join();
    _pacman->pacman_thread->join();
    ghost_b->ghost_thread->join();
    ghost_p->ghost_thread->join();
    ghost_r->ghost_thread->join();
    ghost_y->ghost_thread->join();
    _drawing->_draw->join();



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
        printf("ESTOU na maIN\n");
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
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    std::cout << "Keyboard direita!" << std::endl;
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                    std::cout << "Keyboard para baixo!" << std::endl;
                } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    std::cout << "Keyboard para cima!" << std::endl;
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
}

// void Game::criar_pacman() {
//     while (_window.isOpen()){
//         _semaphore.p();
//         _pacman->pacman_run();
//         _semaphore.v();
//     }
//     pacman_thread->thread_exit(1);
// }

// void Game::criar_ghost(int cor) {

//     switch (cor)
//     {
//     case (0):
//         while (_window.isOpen()){
//             _semaphore.p();
//             ghost_b->ghost_run(cor);
//             _semaphore.v();
//         }
//         ghost_thread_b->thread_exit(5);
//         break;
//     case (1):
//         while (_window.isOpen()){
//             _semaphore.p();
//             ghost_p->ghost_run(cor);
//             _semaphore.v();
//         }
//         ghost_thread_p->thread_exit(6);
//         break;
//     case (2):
//         while (_window.isOpen()){
//             _semaphore.p();
//             ghost_r->ghost_run(cor);
//             _semaphore.v();
//         }
//         ghost_thread_r->thread_exit(7);
//         break;
//     case (3):
//         while (_window.isOpen()){
//             _semaphore.p();
//             ghost_y->ghost_run(cor);
//             _semaphore.v();
//         }
//         ghost_thread_y->thread_exit(8);
//         break;
//     default:
//         break;
//     }

// }

// void Game::desenhar() {

// }

// void Game::ler_input() {

// }









__END_API