# executable file to create and its dependancies
# clear;make;./prog;make clean
prog : driver_phase_2.o Child.o Toy.o Cashier.o ChildUI.o CashierUI.o
	g++ -std=c++11 -o prog driver_phase_2.o Child.o Toy.o Cashier.o ChildUI.o CashierUI.o

# file dependencies
driver_phase_2.o : Child.h Toy.h Files.h
	g++ -std=c++11 -c driver_phase_2.cpp
Child.o : Child.h 
	g++ -std=c++11 -c Child.cpp	
Toy.o : Toy.h
	g++ -std=c++11 -c Toy.cpp
Cashier.o : Cashier.h
	g++ -std=c++11 -c Cashier.cpp	
ChildUI.o : ChildUI.h
	g++ -std=c++11 -c ChildUI.cpp
CashierUI.o : CashierUI.h
	g++ -std=c++11 -c CashierUI.cpp	

# files to remove
clean:
	rm -f *.o
	rm prog