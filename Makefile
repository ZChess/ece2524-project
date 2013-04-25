all: checkers

checkers: main.o global.o movement.o 
	g++ -o checkers main.o global.o movement.o

global.o: global.cc global.hpp
	g++ -c global.cc

movement.o: movement.cc global.hpp movement.hpp
	g++ -c movement.cc

main.o: main.cc global.hpp movement.hpp
	g++ -c main.cc

clean:
	rm -f *.o

#all: global movement main

#global: global.o

#movement: movement.o

#main: main.o

#clean:
#	-rm -f *.o
