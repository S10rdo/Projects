#ifndef FILES_H
#define FILES_H
//Joseph

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Child.h"
#include "Toy.h"
#include "Cashier.h"

void readChild(std::vector<Child*> &vec)
{
    std::ifstream file("Child.csv");
    std::string line, temp;
    while(std::getline(file, line)) {
        std::stringstream parser(line);
        std::string name;
        int id;

        getline(parser, name, ',');
        getline(parser, temp, ',');

        id = stoi(temp);

        Child *c = new Child(name, id);
        vec.push_back(c);
        std::cout << *c << "\n";
    }

    file.close();
}

void readToy(std::vector<Toy*> &vec)
{
    std::ifstream file("Toy.csv");
    std::string line, temp;
    while(std::getline(file, line)) {
        std::stringstream parser(line);
        std::string type;
        int id, maxToys;
        
        getline(parser, type, ',');
        getline(parser, temp, ',');

        id = stoi(temp);

        getline(parser, temp, ',');

        maxToys = std::stoi(temp);

        Toy *t = new Toy(type, id, maxToys);
        vec.push_back(t);
        std::cout<< *t << "\n";
    }

    file.close();
}

template<typename T>
void print(const std::vector<T> &vec)
{
    if (vec.empty()) {
        return;
    }
    for (const auto &ptr : vec) {
        std::cout << *ptr;
    }
}

template<typename T>
void clear(std::vector<T> &vec)
{
    for (auto &ptr : vec) {
        delete ptr;
    }
    vec.clear();
}

#endif