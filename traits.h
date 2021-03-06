#ifndef traits_h
#define traits_h

//Não alterar as 3 declarações abaixo

#define __BEGIN_API             namespace SOLUTION {
#define __END_API               }
#define __USING_API            using namespace SOLUTION;

__BEGIN_API

class CPU; //declaração das classes criadas nos trabalhos devem ser colocadas aqui
class System;
class Debug;
class Thread;
class Lists;
class Timer;
class Ghost;
class Pacman;
class Game;
class Draw;


// declaração da classe Traits
template<typename T>
struct Traits {
};

template<> struct Traits<CPU> : public Traits<void>
{
    static const unsigned int STACK_SIZE = 1024*64; // 64 kB
    static const bool debugged = true;
};

template<> struct Traits<Debug>: public Traits<void>
{
    static const bool error = false;
    static const bool warning = false;
    static const bool info = false;
    static const bool trace = false;
};

template<> struct Traits<System> : public Traits<void>
{
    static const bool debugged = true;
};

template<> struct Traits<Thread> : public Traits<void>
{
    static const bool debugged = true;
};

template<> struct Traits<Lists> : public Traits<void>
{
    static const bool debugged = true;
};

template<> struct Traits<Timer> : public Traits<void>
{
    static const bool debugged = true;
    static const unsigned int q_timer = 20000000;
};

template<> struct Traits<Ghost> : public Traits<void>
{
    static const bool debugged = true;
};

template<> struct Traits<Pacman> : public Traits<void>
{
    static const bool debugged = true;
};

template<> struct Traits<Game> : public Traits<void>
{
    static const bool debugged = true;
};

template<> struct Traits<Draw> : public Traits<void>
{
    static const bool debugged = true;
};

__END_API

#endif
