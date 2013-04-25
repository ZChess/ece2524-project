objects := main.o main.cc
libs = -lboost_program_options

all : main

main : $(objects)
	g++ -o $@ $^ $(libs)

%.o %.cc
	g++ -c -MMD -o $@ $<

-include $(objects:.o=.d)

clean :
	rm -f *.o *.cc
