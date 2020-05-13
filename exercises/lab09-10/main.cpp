#include <iostream>
#include "PrivateCompany.h"
#include "StateCompany.h"
#include "Consortium.h"
#include<fstream>

int main()
{

    // std::cout << c.getName() << std::endl << c1.getName() << std::endl << c2.getName() << std::endl;
    // c = c2;
    // std::cout << c.getName();
    // std::cout << "\n==================\n";

    PrivateCompany c;

    // std::cout << "\n==================\n";
    // c.perform("Learn algebra");
    // c.perform("Learn coding");
    // c.perform("Learn where the hot water is");
    // std::cout << c.reliabilityRate();

    // std::cout << "==================\n";
     StateCompany c1("FMI", 3);
     std::cout << c1.reliabilityRate();
     c1.perform("Learn algebra");
     c1.perform("Learn coding");
     c1.perform("Learn where the hot water is");
     std::cout << c1.reliabilityRate();

    Company** companies = new Company*[2];

    companies[0] = &c;
    companies[1] = &c1;

     Consortium cons1("Name");

    // cons1.perform("Learn algebra");
    // cons1.perform("Learn coding");

    // std::cout << cons1.reliabilityRate();

    //Consortium cons2("Nashta firma", companies, 2);

     

    // std::cout << cons1.reliabilityRate();
    // std::cout << cons2.reliabilityRate();
    // std::cout << cons2.reliabilityRate();

    cons1.setName("test");
    cons1.printStatus(std::cout);

    
    std::cout << "==================\n";
    c.setName("Private");
    cons1.add(&c);
    cons1.add(&c1);
    std::cout << cons1;

    // std::cout << "==================\n";
    // cons1.perform("Learn algebra");
    // cons1.perform("Learn coding");
    // cons1.perform("Learn where the hot water is");
    // cons1.perform("New task 1");
    // cons1.perform("New task 2");
    // cons1.perform("New task 3");
    // cons1.printStatus();

    // std::cout << "==================\n";
    // cons1.remove("");
    // cons1.printStatus(std::cout);

    // std::cout << cons1;

    std::ofstream out("companies.txt");
    out << cons1;
}