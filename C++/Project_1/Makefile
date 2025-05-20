#include <iostream>

# combine these commands as follows into one line 
# to rapidly run and update code: 
# clear;make;./prog;make clean

# executable file to create and its dependancies
prog : driver_phase3.o floatArray.o Files.o Algorithms.o
	g++ -std=c++11 -o prog driver_phase3.o floatArray.o Files.o Algorithms.o

# file dependencies
driver_phase3.o : Files.h
	g++ -std=c++11 -c driver_phase3.cpp
floatArray.o : floatArray.h 
	g++ -std=c++11 -c floatArray.cpp
Files.o : Files.h 
	g++ -std=c++11 -c Files.cpp
Algorithms.o : Algorithms.h 
	g++ -std=c++11 -c Algorithms.cpp
# remove all object and executable files
clean:
	rm -f *.o
	rm prog