#ifndef TOY_H
#define TOY_H
//Stanley

#include <iostream>
#include <vector>
#include "Child.h"

class Child;

class Toy {
    private:
        std::string type;
        int id;
        int maxToys;
        std::vector<Child*> children;
    public:
        Toy();
        Toy(std::string type, int id, int maxToys);
        std::string getToyType() const;
        int getToyId() const;
        int getToyMax() const;
        void setToyType(const std::string &t);
        void setToyId(const int &i);
        void setToyMax(const int &m);

        bool operator==(const Toy &toy2) const;
        friend std::ostream& operator<<(std::ostream &out, const Toy &toy);
        
        void display();
        const std::vector<Child*> &getChildren() const;
        int getNumChildren() const;
        bool isFull() const;
        void increaseMax();
        void removeToy();

        void addChild(Child* c);
        void removeChild(Child* c);
    };
   

#endif