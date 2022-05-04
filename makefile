main: main.cc main_class.cc cpu.cc
	g++ -o main main.cc main_class.cc cpu.cc

clean:
	rm main
