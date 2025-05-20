#include "Cashier.h"
//Joseph

std::vector<Toy*>::iterator Cashier::findToy(std::vector<Toy*>& toys, int toyId) {
    for (auto it = toys.begin(); it != toys.end(); ++it) {
        if ((*it)->getToyId() == toyId) {
            return it;
        }
    }
    return toys.end(); 
}


void Cashier::createToy(std::vector<Toy*>& toys, const std::string& type, int id, int maxToys) {
    Toy* newToy = new Toy(type, id, maxToys);
    toys.push_back(newToy);
}


void Cashier::removeToy(std::vector<Toy*>& toys, Toy* toy, std::vector<Child*>& children) {
    
    for (auto it = toys.begin(); it != toys.end(); ++it) {
        if (*it == toy) {
            toys.erase(it);
            break; 
        }
    }

   
    for (Child* child : children) {
        auto& childToys = child->getToys();
        for (auto it = childToys.begin(); it != childToys.end(); ++it) {
            if (*it == toy) {
                childToys.erase(it);
                break;  
            }
        }
    }

    delete toy;
}