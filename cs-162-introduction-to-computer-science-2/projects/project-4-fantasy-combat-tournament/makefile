all, Project4, Project4.exe: Character.o Barbarian.o BlueMen.o Vampire.o Medusa.o HarryPotter.o LinkedList.o Queue.o Stack.o main.o
	g++ main.o Character.o Barbarian.o BlueMen.o Vampire.o Medusa.o HarryPotter.o LinkedList.o Queue.o Stack.o -o Project4

CXXFLAGS += -std=c++11

Character.o: Character.cpp Character.h
	g++ -c Character.cpp

Barbarian.o: Barbarian.cpp Barbarian.h
	g++ -c Barbarian.cpp

BlueMen.o: BlueMen.cpp BlueMen.h
	g++ -c BlueMen.cpp

Vampire.o: Vampire.cpp Vampire.h
	g++ -c Vampire.cpp

Medusa.o: Medusa.cpp Medusa.h
	g++ -c Medusa.cpp

HarryPotter.o: HarryPotter.cpp HarryPotter.h
	g++ -c HarryPotter.cpp

LinkedList.o: LinkedList.cpp LinkedList.h
	g++ -c LinkedList.cpp

Queue.o: Queue.cpp Queue.h
	g++ -c Queue.cpp

Stack.o: Stack.cpp Stack.h
	g++ -c Stack.cpp

main.o: main.cpp Character.h Barbarian.h BlueMen.h Vampire.h Medusa.h HarryPotter.h LinkedList.h Queue.h Stack.h
	g++ -std=c++11 -c main.cpp

clean:
	-rm *.o
