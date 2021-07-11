all, Project3, Project3.exe: Character.o Barbarian.o BlueMen.o Vampire.o Medusa.o HarryPotter.o main.o
	g++ main.o Character.o Barbarian.o BlueMen.o Vampire.o Medusa.o HarryPotter.o -o Project3

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

main.o: main.cpp Character.h Barbarian.h BlueMen.h Vampire.h Medusa.h HarryPotter.h
	g++ -c main.cpp

clean:
	-rm *.o
