#include <iostream>
#include <fstream>
#include <sstream>
#include "Car.h"
#include "List.h"

void read(List &cars){ 
    std::ifstream file("data.csv");
    std::string line, token;

    while(getline(file, line)){   
        std::stringstream parser(line);
        std::string model;
        int year;
        getline(parser, model, ',');
        getline(parser, token, ',');         
        year = stoi(token);
        Car c(model, year);
        cars.push_back(c);
    } 
    file.close();
}


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

    List cars;
    read(cars);
    cars.print();


    return 0;
}