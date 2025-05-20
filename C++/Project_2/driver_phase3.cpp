#include <iostream>
#include "Car.h"
#include "List.h"

int main() {
    std::cout << std::endl;

    Car c1;
    c1.print();
    c1.setName("Mazda");
    c1.print();
    c1.setYear(2014);
    c1.print();

    std::cout << std::endl;

    Car c2("Mazda",2012);
    c2.print();
    c2.getName();
    c2.getYear();

    std::cout << std::endl;

    std::cout << Equivalent(c1,c2) << std::endl;
    std::cout << Compare(c1,c2,1) << std::endl;

    c2.setYear(2014);
    c2.print();
    c1.print();

    std::cout << std::endl;

    std::cout << Equivalent(c1,c2) << std::endl;
    std::cout << Compare(c1,c2,1) << std::endl;
    std::cout << Compare(c1,c2,0) << std::endl;

    std::cout << std::endl;

    List l1, l2, l3;
    Car c3("Tesla",2006),c4("Toyota",2017);

    l1.push_back(c1);
    l1.push_back(c3);
    l1.print();

    l2.push_back(c2);
    l2.push_back(c4);
    l2.print(); 

    List::merge(l1, l2, l3, true);
    l3.print();

    List cars;
    cars.push_back(c1);
    cars.push_back(c2);
    cars.push_back(c3);
    cars.push_back(c4);

    std::cout << "Before mergeSort:\n";
    cars.print();

    //List::mergeSort(cars, true); //Smallest to Large
    List::mergeSort(cars, false); //Largest to Small
    std::cout << "After mergeSort:\n";
    cars.print();

    std::cout << std::endl;
    std::cout << std::endl;

    List::reverse(cars);
    cars.print();

    return 0;
}