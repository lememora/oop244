# Makefile for Workshop 5 - GCC Platform

#----------------------------------------------------------
# Platform Variables

OPT=-Wall -std=c++0x

#----------------------------------------------------------
# Set of Rules

# links the binary components together to form the executable
w5: w5.o Grade.o
	g++ -o w5 w5.o Grade.o

# recompiles w5.cpp if any recent changes have affected it
w5.o: w5.cpp
	g++ -c $(OPT) w5.cpp

# recompiles Grade.cpp if any recent changes have affected it
Grade.o: Grade.cpp Grade.h
	g++ -c $(OPT) Grade.cpp

# removes intermediate files
clean:
	rm -f *.o
