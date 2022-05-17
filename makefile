main: main.cc main_class.cc cpu.cc debug.cc system.cc thread.cc
	g++ -o main main.cc main_class.cc cpu.cc debug.cc system.cc thread.cc

clean:
	rm main
