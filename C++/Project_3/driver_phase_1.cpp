#include "Files.h"

int main(){

    std::vector<Child*> children;
    std::vector<Toy*> toys;

    readChild(children);

    std::cout << std::endl;

    readToy(toys);

    std::cout << std::endl;

    Child* c1 = new Child();
    c1->setName("Alice");
    c1->setId(5000);

    std::cout << std::endl;

    std::cout << c1->getName() << std::endl;
    std::cout << c1->getId() << std::endl;
  
    std::cout << std::endl;

    std::cout << *c1 << std::endl;

    Child* c2 = new Child("Bob", 5001);
    std::cout << *c2 << std::endl;

    std::cout << (*c1 == *c2) << std::endl;

        Toy* t1 = new Toy();
    t1->setToyType("Plushie");
    t1->setToyId(6000);
    t1->setToyMax(3);

    std::cout << std::endl;

    std::cout << t1->getToyType() << std::endl;
    std::cout << t1->getToyId() << std::endl;
    std::cout << t1->getToyMax() << std::endl;  
   
    std::cout << std::endl;

    std::cout << *t1 << std::endl;

    Toy* t2 = new Toy("Plushie", 6000, 3);
    std::cout << *t2 << std::endl;

    std::cout << (*t1 == *t2) << std::endl;

    return 0;
}