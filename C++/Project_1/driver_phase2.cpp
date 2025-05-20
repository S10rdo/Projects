#include <iostream>
#include "Files.h"

int main()
{
    std::cout << std::endl;
    floatArray c1;
    std::cout << c1.size() << " (DEFAULT)" << std::endl;
    std::cout << c1.maxsize() << " (DEFAULT)" << std::endl;
    c1.print();
    std::cout << c1.empty() << std::endl;
    c1.reserve(5);

    c1.push_back(10.1);
    c1.push_back(20.3);
    c1.push_back(30.4);
    c1.push_back(40.5);
    c1.push_back(50.6);
    c1.push_back(60.7);
    c1.print();
    
    std::cout << c1.size() << " (Data Size)" << std::endl;
    std::cout << c1.maxsize() << " (Capacity Size)" << std::endl;

    c1.sortedInsert(45.6);
    c1.print();
    c1.sortedInsert(25.6);
    c1.print();
    c1.sortedInsert(5.6);
    c1.print();
    c1.sortedInsert(55.6);
    c1.print();
    c1.sortedInsert(65.6);
    c1.print();

    c1.resize(11);
    std::cout << c1.size() << " (Data Size)" << std::endl;
    c1.resize(20);
    std::cout << c1.size() << " (Data Size)" << std::endl;
    c1.print();
    c1.resize(5);
    std::cout << c1.size() << " (Data Size)" << std::endl;
    c1.resize(5);
    std::cout << c1.size() << " (Data Size)" << std::endl;
    c1.print();
    c1.resize(0);
    std::cout << c1.size() << " (Data Size)" << std::endl;
    c1.print();
    

    std::cout << std::endl;
    std::cout << std::endl;

    floatArray c2(8,2);
    std::cout << c2.size() << " (PARAMETERIZED)" << std::endl;
    std::cout << c2.maxsize() << " (PARAMETERIZED)" << std::endl;
    c2.print();
    std::cout << c2.empty() << std::endl;
    c2.clear();
    std::cout << c2.size() << " (DEFAULT)" << std::endl;
    std::cout << c2.maxsize() << " (DEFAULT)" << std::endl;
    
    c2.print();
    std::cout << c2.empty() << std::endl;

    std::cout << std::endl;

    floatArray c3;
    read(c3);
    c3.print();


    c3.pop_back();
    c3.print();

    c3.at(2);

    c3.erase(1,3);
    c3.print();
    /* Assertion tests
    c3.erase(-1,2); 
    c3.print();
    
    c3.erase(2,3);
    std::cout << std::endl; 

    c3.resize(-1);
    */
    
    return 0;
}