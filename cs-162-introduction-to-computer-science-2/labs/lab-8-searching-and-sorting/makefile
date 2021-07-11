all, Lab8, Lab8.exe: readValues.o simpleSearch.o sorting.o binarySearch.o main.o
	g++ readValues.o simpleSearch.o sorting.o binarySearch.o main.o -o Lab8

readValues.o: readValues.cpp readValues.h
	g++ -c readValues.cpp

simpleSearch.o: simpleSearch.cpp simpleSearch.h
	g++ -c simpleSearch.cpp

sorting.o: sorting.cpp sorting.h
	g++ -c sorting.cpp

binarySearch.o: binarySearch.cpp binarySearch.h
	g++ -c binarySearch.cpp

main.o: main.cpp readValues.h simpleSearch.h sorting.h binarySearch.h
	g++ -c main.cpp

clean:
	-rm *.o
