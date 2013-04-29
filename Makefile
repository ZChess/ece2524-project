all: checkers


checkers: main.o global.o movement.o ai.o
	g++ -o checkers main.o global.o movement.o ai.o

ai.o: ai.cc ai.hpp
	g++ -c ai.cc

global.o: global.cc global.hpp
	g++ -c global.cc

movement.o: movement.cc global.hpp movement.hpp
	g++ -c movement.cc

main.o: main.cc global.hpp movement.hpp
	g++ -c main.cc

clean:
	rm -f *.o

