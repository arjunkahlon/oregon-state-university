all, lab4, lab4.exe: Person.o Building.o Student.o Instructor.o University.o main.o
	g++ main.o Person.o Building.o Student.o Instructor.o University.o -o lab4

Person.o: Person.cpp Person.h
	g++ -c Person.cpp

Building.o: Building.cpp Building.h
	g++ -c Building.cpp

Student.o: Student.cpp Student.h
	g++ -c Student.cpp

Instructor.o: Instructor.cpp Instructor.h
	g++ -c Instructor.cpp

University.o: University.cpp University.h
	g++ -c University.cpp

main.o: main.cpp Person.h Building.h Student.h Instructor.h University.h
	g++ -c main.cpp

clean:
	-rm *.o
