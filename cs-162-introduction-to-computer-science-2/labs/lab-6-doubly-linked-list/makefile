all, Lab6, Lab6.exe: Node.o addNodeHead.o addNodeTail.o printMenu.o printList.o main.o
	g++ Node.o addNodeHead.o addNodeTail.o printMenu.o printList.o main.o -o Lab6

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

addNodeHead.o: addNodeHead.cpp addNodeHead.h
	g++ -c addNodeHead.cpp

addNodeTail.o: addNodeTail.cpp addNodeTail.h
	g++ -c addNodeTail.cpp

printMenu.o: printMenu.cpp printMenu.h
	g++ -c printMenu.cpp

printList.o: printList.cpp printList.h
	g++ -c printList.cpp

main.o: main.cpp Node.h addNodeHead.h addNodeTail.h printMenu.h printList.h 
	g++ -c main.cpp

clean:
	-rm *.o
