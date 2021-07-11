all, Lab7, Lab7.exe: Queue.o main.o
	g++ Queue.o main.o -o Lab7

Queue.o: Queue.cpp Queue.h
	g++ -c Queue.cpp

main.o: main.cpp Queue.h
	g++ -c main.cpp

clean:
	-rm *.o
