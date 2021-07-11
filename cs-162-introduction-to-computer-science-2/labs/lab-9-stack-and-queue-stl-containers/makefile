all, Lab9, Lab9.exe: bufferSimulation.o palindrome.o main.o
	g++ main.o bufferSimulation.o palindrome.o -o Lab9

CXXFLAGS += -std=c++11

Character.o: bufferSimulation.cpp bufferSimulation.h
	g++ -std=c++11 -c bufferSimulation.cpp

Barbarian.o: palindrome.cpp palindrome.h
	g++ -std=c++11 -c palindrome.cpp

main.o: main.cpp bufferSimulation.cpp palindrome.cpp
	g++ -std=c++11 -c main.cpp

clean:
	-rm *.o
