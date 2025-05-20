#include "Child.h"
#include "Toy.h"
//Hong Wei
Child::Child(): name(""), id(0), toys() {}
Child::Child(std::string name, int id): name(std::move(name)), id(id), toys() {}
std::string Child::getName() const 
{
    return name;
}
int Child::getId() const 
{
    return id;
}
void Child::setName(const std::string& newName) 
{
    name = newName;
}
void Child::setId(int newId) 
{
    id = newId;
}
bool Child::operator==(const Child& other) const 
{
    return (name == other.name) && (id == other.id);
}
    
std::ostream& operator<<(std::ostream& out, const Child& child) 
{
    out << std::left
        << std::setw(20) << child.name
        << std::setw(10) << child.id;
    return out;
}
void Child::display() const 
{
    std::cout << std::endl;
    std::cout << "Child Name: " << this->name << "\n";
    std::cout << "Child ID:   " << this->id << "\n";
    std::cout << std::endl;

    if(toys.empty()){
        std::cout << "The child does not have toy" << std::endl;
        return;
    }
    std::cout << std::left
    << std::setw(20) << "Toy Type"
    << std::setw(10) << "Toy ID" 
    << std::setw(15) << "MaxToys" << "\n";
    std::cout << std::string(40, '-') << '\n';
    for (const Toy* toy : toys) {
        std::cout << std::left
        << std::setw(20) << toy->getToyType()
        << std::setw(10) << toy->getToyId() 
        << std::setw(15) << toy->getToyMax() << "\n";
    }
}
std::vector<Toy*>& Child::getToys() 
{
     return toys;
}
int Child::getNumToys() const 
{
    return toys.size();
}
void Child::clear() 
{
    toys.clear();
}
void Child::orderToy(Toy* toy) 
{
    bool found = false;
        for (auto* t : toys) {
        if (t == toy) {
            found = true;
            break;
            }
        }
        if (!found && getNumToys() < toy->getToyMax()) {
        toys.push_back(toy);
    }
}
void Child::returnToy(Toy* toy) 
{
    for (auto it = toys.begin(); it != toys.end(); ++it) {
        if (*it == toy) {
             toys.erase(it);
             break; 
        }
    }
}