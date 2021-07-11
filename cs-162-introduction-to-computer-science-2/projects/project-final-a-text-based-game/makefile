all, RiddleDungeon, RiddleDungeon.exe: Space.o Beginning.o Passage.o Final.o getInput.o main.o
	g++ main.o Space.o Beginning.o Passage.o Final.o getInput.o -o RiddleDungeon

CXXFLAGS += -std=c++11

Space.o: Space.cpp Space.h
	g++ -std=c++11 -c Space.cpp

Beginning.o: Beginning.cpp Beginning.h
	g++ -std=c++11 -c Beginning.cpp

Passage.o: Passage.cpp Passage.h
	g++ -std=c++11 -c Passage.cpp

Final.o: Final.cpp Final.h
	g++ -std=c++11 -c Final.cpp

getInput.o: getInput.cpp getInput.h
	g++ -std=c++11 -c getInput.cpp

main.o: main.cpp Space.h Beginning.h Passage.h Final.h getInput.h
	g++ -std=c++11 -c main.cpp

clean:
	-rm *.o
