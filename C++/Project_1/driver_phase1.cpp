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
    //c1.reserve(4); tested assertion
    c1.push_back(10.1);
    c1.push_back(20.3);
    c1.push_back(30.4);
    c1.push_back(40.5);
    c1.push_back(50.6);
    c1.push_back(60.7);
    c1.print();
    std::cout << c1.size() << " (Data Size)" << std::endl;
    std::cout << c1.maxsize() << " (Capacity Size)" << std::endl;
    

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

    floatArray c3;
    read(c3);
    c3.print();

    std::cout << std::endl;

    return 0;
}