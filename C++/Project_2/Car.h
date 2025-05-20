#ifndef CAR_H
#define CAR_H
#include <iostream>

class Car {       
private:                                        
    std::string model;                      //data members
    int year;
public:
    Car();                                  //Default Constructor
    Car(std::string model,int year);        //Parameter Constructor
    std::string getName() const;            //Accessor
    int getYear() const;                    //Accessor
    void setName(const std::string &n);            //Mutator
    void setYear(const int &y);                    //Mutator
    void print() const;                     //Print const member function
};
    bool Equivalent(const Car &p1,const Car &p2);      //non-member function
    bool Compare(const Car &p1,const Car &p2, bool comparator);
    

#endif