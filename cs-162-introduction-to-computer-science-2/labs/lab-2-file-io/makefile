all, lab2, lab2.exe: count_letters.o output_letters.o main.o
	g++ main.o count_letters.o output_letters.o -o lab2

count_letters.o: count_letters.cpp count_letters.hpp
	g++ -c count_letters.cpp

output_letters.o: output_letters.cpp output_letters.hpp
	g++ -c output_letters.cpp

main.o: main.cpp count_letters.hpp output_letters.hpp
	g++ -c main.cpp

clean:
	-rm *.o

