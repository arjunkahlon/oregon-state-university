all, project2, project2.exe: Animal.o Tiger.o Penguin.o Turtle.o Zoo.o main.o
	g++ main.o Animal.o Tiger.o Penguin.o Turtle.o Zoo.o -o project2

Animal.o: Animal.cpp Animal.h
	g++ -c Animal.cpp

Tiger.o: Tiger.cpp Tiger.h
	g++ -c Tiger.cpp

Penguin.o: Penguin.cpp Penguin.h
	g++ -c Penguin.cpp

Turtle.o: Turtle.cpp Turtle.h
	g++ -c Turtle.cpp

Zoo.o: Zoo.cpp Zoo.h
	g++ -c Zoo.cpp

main.o: main.cpp Animal.h Tiger.h Penguin.h Turtle.h Zoo.h
	g++ -c main.cpp

clean:
	-rm *.o
