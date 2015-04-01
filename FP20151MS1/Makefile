# Makefile for FP20151MS1 - GCC Platform

#----------------------------------------------------------
# Platform Variables

OPT=-Wall -std=c++0x

#----------------------------------------------------------
# Set of Rules

# links the binary components together to form the executable
dateTester.cpp: dateTester.o date.o
	g++ -o dateTester dateTester.o date.o

# recompiles dateTester.cpp if any recent changes have affected it
dateTester.o: dateTester.cpp
	g++ -c $(OPT) dateTester.cpp

# recompiles date.cpp if any recent changes have affected it
date.o: date.cpp date.h general.h
	g++ -c $(OPT) date.cpp

# removes intermediate files
clean:
	rm -f *.o dateTester
