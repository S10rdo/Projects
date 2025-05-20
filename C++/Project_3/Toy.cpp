#include "Toy.h"
#include "Child.h"
//Stanley

Toy::Toy():type(""),id(0),maxToys(0), children()
{}
Toy::Toy(std::string t, int i, int m): type(t), id(i), maxToys(m), children()
{}
std::string Toy::getToyType() const
{
    return type;
}
int Toy::getToyId() const
{
    return id;
}
int Toy::getToyMax() const
{
    return maxToys;
}
void Toy::setToyType(const std::string &t)
{
    type = t;
}
void Toy::setToyId(const int &i)
{
    id = i;
}
void Toy::setToyMax(const int &m)
{
    maxToys = m;
}
bool Toy::operator==(const Toy &toy2) const 
{
    return (type == toy2.type) && (id == toy2.id) && (maxToys == toy2.maxToys);
}
std::ostream& operator<<(std::ostream &out, const Toy &toy) 
{
    out << std::left
        << std::setw(20) << toy.type
        << std::setw(10) << toy.id
        << std::setw(15) << toy.maxToys;
        return out;
}
void Toy::display()
{
    std::cout << std::endl;
    std::cout << "Toy Name: " << this->type << "\n";
    std::cout << "Toy ID:   " << this->id << "\n";
    std::cout << std::endl;

    if (children.empty()){
        return;
    }
    std::cout << std::left
    << std::setw(20) << "Child Name"
    << std::setw(10) << "Child ID" << '\n';
    std::cout << std::string(30, '-') << '\n';
    for (const Child* Child : children) {
        std::cout << std::left 
        << std::setw(20) << Child->getName() 
        << std::setw(10) << Child->getId() << '\n';
    }
}
const std::vector<Child*> &Toy::getChildren() const
{
    return children;
}
int Toy::getNumChildren() const
{
    return children.size();
}
bool Toy::isFull() const
{
    return children.size() >= maxToys;
}
void Toy::increaseMax()
{
    ++maxToys;
}
void Toy::removeToy()
{
    children.clear();
}
void Toy::addChild(Child* child) {
    if (child && !isFull()) { 
        children.push_back(child);
    }
}
void Toy::removeChild(Child* c)
{
    if(!c) 
    { 
        return;
    }
    for (auto current = children.begin(); current != children.end(); ++current){
        if (*current == c){
            children.erase(current);
            break;
        }
    }
}