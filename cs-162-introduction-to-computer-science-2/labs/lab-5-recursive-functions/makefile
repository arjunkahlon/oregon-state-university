all, lab5, lab5.exe: reverseString.o arraySum.o triangular.o main.o
	g++ main.o reverseString.o arraySum.o triangular.o -o lab5

reverseString.o: reverseString.cpp reverseString.h
	g++ -c reverseString.cpp

arraySum.o: arraySum.cpp arraySum.h
	g++ -c arraySum.cpp

triangular.o: triangular.cpp triangular.h
	g++ -c triangular.cpp

main.o: main.cpp reverseString.h arraySum.h triangular.h
	g++ -c main.cpp

clean:
	-rm *.o

