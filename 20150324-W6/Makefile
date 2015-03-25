# Makefile for Workshop 5 - GCC Platform

#----------------------------------------------------------
# Platform Variables

OPT=-Wall -std=c++0x

#----------------------------------------------------------
# Set of Rules

# links the binary components together to form the executable
w6: w6.o Grade.o
	g++ -o w6 w6.o Grade.o

# recompiles w6.cpp if any recent changes have affected it
w6.o: w6.cpp
	g++ -c $(OPT) w6.cpp

# recompiles Grade.cpp if any recent changes have affected it
Grade.o: Grade.cpp Grade.h
	g++ -c $(OPT) Grade.cpp

# removes intermediate files
clean:
	rm -f *.o
