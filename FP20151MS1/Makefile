# Makefile for FP20151MS1 - GCC Platform

#----------------------------------------------------------
# Platform Variables

OPT=-Wall -std=c++0x

#----------------------------------------------------------
# Set of Rules

# links the binary components together to form the executable
#dateTester.cpp: dateTester.o Date.o
#	g++ -o dateTester dateTester.o Date.o

# links the binary components together to form the executable
ms1.cpp: ms1.o Date.o
	g++ -o ms1 ms1.o Date.o

# recompiles dateTester.cpp if any recent changes have affected it
#dateTester.o: dateTester.cpp
#	g++ -c $(OPT) dateTester.cpp

# recompiles ms1.cpp if any recent changes have affected it
ms1.o: ms1.cpp
	g++ -c $(OPT) ms1.cpp

# recompiles Date.cpp if any recent changes have affected it
Date.o: Date.cpp Date.h general.h
	g++ -c $(OPT) Date.cpp

# removes intermediate files
clean:
	rm -f *.o ms1 dateTester
