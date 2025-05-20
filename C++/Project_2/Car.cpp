#include "Car.h" //Joseph


        Car::Car(): model("noname"), year(2000)                          //Default Constructor
        {}                                  
        Car::Car(std::string m,int y): model(m), year(y)                 //Parameter Constructor
        {}             
        std::string Car::getName() const                                 //Accessor
        {
            return model;
        }                
        int Car::getYear() const                                         //Accessor
        {
            return year;
        }                      
        void Car::setName(const std::string &n)                                 //Mutator
        {
            model = n;
        }           
        void Car::setYear(const int &y)                                         //Mutator
        {
            year = y;
        }                    
        void Car::print() const                                          //Print const member function
        {
            std::cout << "Car Model: " << model << ", Year: " << year << std::endl;
        }                   
        bool Equivalent(const Car &p1, const Car &p2)         //non-member function         //Hong Wei
        {
            if(p1.getName() == p2.getName() && p1.getYear() == p2.getYear()){
                return true;
            } else {
                return false;
            }
        }              
        bool Compare(const Car &p1, const Car &p2, bool comparator)         //Stanley
        {
            if(comparator == true){
                return p1.getYear() <= p2.getYear();
            } else {
                return p1.getYear() > p2.getYear();
            }
        }

