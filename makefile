
IDIR =.
CC=g++
LDLIBS =  -lsfml-graphics -lsfml-window -lsfml-system -lm  -lpng
CFLAGS=-I$(IDIR) -g -Wextra

LDFLAGS= $(CFLAGS)

ODIR=.
LIBS= $(LDLIBS) $(LDFLAGS)

_DEPS = cpu.h debug.h draw.h game.h ghost.h main_class.h pacman.h semaphore.h system.h thread.h timer.h traits.h input.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o main_class.o cpu.o debug.o system.o thread.o semaphore.o draw.o game.o ghost.o pacman.o timer.o input.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -std=c++14 -c -o $@ $< $(CFLAGS) -Wextra

main: $(OBJ)
	$(CC) -std=c++14 -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
