all, langton, langton.exe: Board.o Ant.o menuLangton.o main.o
	g++ main.o Board.o Ant.o menuLangton.o -o langton

Board.o: Board.cpp Board.hpp
	g++ -c Board.cpp

Ant.o: Ant.cpp Ant.hpp
	g++ -c Ant.cpp

menuLangton.o: menuLangton.cpp menuLangton.h
	g++ -c menuLangton.cpp

main.o: main.cpp Board.hpp Ant.hpp menuLangton.h
	g++ -c main.cpp

clean:
	-rm *.o

