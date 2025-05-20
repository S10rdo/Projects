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

    std::cout << std::endl;
//Phase 2
//Testing Child functions
    Child* c10 = new Child("Stanley", 8000);
    Toy* t6 = new Toy("Robot", 7001, 6);
    Toy* t7 = new Toy("Truck", 7002, 2);
    Toy* t8 = new Toy("Guitar", 7003, 4);
    Toy* t9 = new Toy("Basketball", 7004, 4);
    
    c10->orderToy(t6);
    c10->orderToy(t7);
    c10->orderToy(t8);
    c10->orderToy(t9);

    std::cout << "Child Name: " << c10->getName() << std::endl;
    std::cout << "Child ID: " << c10->getId() << std::endl;

    c10->display();
    std::cout << "Number of Toy ordered by child: " << c10->getNumToys() << std::endl;
    std::cout << std::endl;

    c10->returnToy(t6);
    c10->display();
    c10->clear();
    c10->display();
    std::cout << std::endl;

//Testing Toy functions
    Toy* t3 = new Toy("Rubix Cube", 7000, 5);   
    Child* c4 = new Child("Max", 4);
    Child* c5 = new Child("Sam", 5);
    Child* c6 = new Child("George", 6);
    Child* c7 = new Child("Vanessa",7);
    t3->addChild(c4);   
    t3->addChild(c5);
    t3->addChild(c6);
    t3->addChild(c7);
    std::cout << "Toy Type: " << t3->getToyType() << std::endl;
    std::cout << "Toy ID: " << t3->getToyId() << std::endl;
    std::cout << "Max # of Toys: " << t3->getToyMax() << std::endl;

    t3->display();  
    std::cout << std::endl;
    std::cout << "Number of Children with this Toy: " << t3->getNumChildren() << std::endl;
    std::cout << "Maximum Amount of this Toy: " << t3->getToyMax() << std::endl;

    std::cout << std::endl;
    t3->removeChild(c6);    
    t3->display();
    std::cout << std::endl;

    std::cout << "Number of Children with this Toy: " << t3->getNumChildren() << std::endl;
    t3->increaseMax();
    std::cout << "Maximum Amount of this Toy: " << t3->getToyMax() << std::endl;
    std::cout << t3->isFull() << std::endl;
    std::cout << std::endl;
//Test for Cashier function
    Cashier::createToy(toys, "Action Figure", 2005 ,2);
    Cashier::createToy(toys, "Hockey", 2006 ,3);

    for (Toy* toy : toys) {
    toy->display();
}
    auto it = Cashier::findToy(toys, 2002);
    if(it != toys.end()){
        std::cout << "Found toy: " << (*it)->getToyType() << "\n";
        Cashier::removeToy(toys, *it, children);
    }

   for (Toy* toy : toys) {
    toy->display();
}

    return 0;
}