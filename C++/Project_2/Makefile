# include <iostream>

# combine these commands as follows into one line 
# to rapidly run and update code: 
# clear;make;./prog;make clean

# executable file to create and its dependancies
prog : driver_phase3.o Node.o List.o Iterator.o Car.o
	g++ -std=c++11 -o prog driver_phase3.o Node.o List.o Iterator.o Car.o

# file dependencies
driver_phase3.o : Node.h List.h Car.h
	g++ -std=c++11 -c driver_phase3.cpp
Node.o : Node.h 
	g++ -std=c++11 -c Node.cpp
List.o : List.h 
	g++ -std=c++11 -c List.cpp
Iterator.o : Iterator.h 
	g++ -std=c++11 -c Iterator.cpp
Car.o : Car.h
	g++ -std=c++11 -c Car.cpp
# remove all object and executable files
clean:
	rm -f *.o
	rm prog