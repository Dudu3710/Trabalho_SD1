all: main

main.o: main.cc thread.h system.h main_class.h
main_class.o: main_class.cc main_class.h
cpu.o: cpu.cc cpu.h
debug.o: debug.cc debug.h
system.o: system.cc system.h
thread.o: thread.cc thread.h

$(EXEC_FILE): main.o main_class.o cpu.o debug.o system.o thread.o
	$(CC) $^ -o $@

clean:
	rm -f main
	rm -f *.o
