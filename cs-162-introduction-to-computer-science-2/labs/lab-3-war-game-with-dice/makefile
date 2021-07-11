all, lab3, lab3.exe: Die.o loadedDie.o game.o main.o
	g++ main.o Die.o loadedDie.o game.o -o lab3

Die.o: Die.cpp Die.hpp
	g++ -c Die.cpp

loadedDie.o: loadedDie.cpp loadedDie.hpp
	g++ -c loadedDie.cpp

game.o: game.cpp game.hpp
	g++ -c game.cpp

main.o: main.cpp Die.hpp loadedDie.hpp game.hpp
	g++ -c main.cpp

clean:
	-rm *.o
