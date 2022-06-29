CC := g++

all: main

main.o: main.cc
main_class.o: main_class.cc
cpu.o: cpu.cc
debug.o: debug.cc
system.o: system.cc
thread.o: thread.cc
semaphore.o: semaphore.cc
	$(CC) -c $^

main: main.o main_class.o cpu.o debug.o system.o thread.o semaphore.o
	$(CC) $^ -o $@

clean:
	rm -f main
	rm -f *.o
