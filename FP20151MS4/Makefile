# Makefile for FP20151MS4 - GCC Platform
OPT=-Wall -std=c++0x

Perishable.o: Perishable.cpp Perishable.h
	g++ $(OPT) Perishable.cpp

ErrorMessage.o: ErrorMessage.cpp ErrorMessage.h
	g++ $(OPT) ErrorMessage.cpp

NFI.o: NFI.cpp NFI.h
	g++ $(OPT) NFI.cpp

PerishableTester: Perishable.o ErrorMessage.o
	g++ $(OPT) PerishableTester.cpp Perishable.o ErrorMessage.o -o PerishableTester

nfiTester: NFI.o ErrorMessage.o
	g++ $(OPT) nfiTester.cpp NFI.o ErrorMessage.o -o nfiTester

nfipshTester: NFI.o Perishable.o ErrorMessage.o
	g++ $(OPT) nfipshTester.cpp NFI.cpp Perishable.cpp ErrorMessage.cpp -o nfipshTester

clean:
	rm -f *.o ItemTester PerishableTester nfiTester nfipshTester
