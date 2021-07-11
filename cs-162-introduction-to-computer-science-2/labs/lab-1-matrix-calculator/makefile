all, lab1, lab1.exe: readMatrix.o determinant.o main.o
	g++ main.o readMatrix.o determinant.o -o lab1

readMatrix.o: readMatrix.cpp readMatrix.h
	g++ -c readMatrix.cpp

determinant.o: determinant.cpp determinant.h
	g++ -c determinant.cpp

main.o: main.cpp readMatrix.h determinant.h
	g++ -c main.cpp

clean:
	-rm *.o

