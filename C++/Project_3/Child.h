#ifndef CHILD_H
#define CHILD_H
//Hong Wei

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>


class Toy;

class Child {
private:
    std::string name;
    int id;
    std::vector<Toy*> toys;
public:
    Child();                                                                
    Child(std::string name, int id);                                        
    std::string getName() const;                                            
    int getId() const;                                                      
    void setName(const std::string& name);                                  
    void setId(int id);                                                     
    bool operator==(const Child& other) const;                              
    friend std::ostream& operator<<(std::ostream& os, const Child& child);  

    void display() const;                                                   
    std::vector<Toy*>& getToys();                                           
    int getNumToys() const;                                                 
    void clear();                                                           
    void orderToy(Toy* toy);                                                
    void returnToy(Toy* toy);                                               
    };


#endif