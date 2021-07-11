Arjun Kahlon
Program 4

To compile:

gcc --std=gnu99 -pthread -o line_processor main.c


To run:

./line_processor
./line_processor > (output file)
./line_processor < (input file) 
./line_processor < (input file) > (output file)


*Notes

This program runs perfectly when no input file is specified in the run statement.

However, the shell does not seem to properly handle input file redirection

I've tried numerous alternatives, and would love feedback on why input redirection is not working on my implementation. Other students in the course seem to run into the same issue. The program creates a 0 Byte file. I believe this may be due to the output being overwritten. Or possibly file permissions. The functionality in the program works fine with shell I/O and writing to an output file. I'm disappointed that I could figure out this input file redirection issue I've been having. 



