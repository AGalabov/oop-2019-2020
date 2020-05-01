#include <iostream>
#include "PrivateCompany.h"
#include "StateCompany.h"
#include "Consortium.h"

int main()
{

    // std::cout << c.getName() << std::endl << c1.getName() << std::endl << c2.getName() << std::endl;
    // c = c2;
    // std::cout << c.getName();
    // std::cout << "\n==================\n";

    PrivateCompany c;

    std::cout << "\n==================\n";
    c.perform("Learn algebra");
    c.perform("Learn coding");
    c.perform("Learn where the hot water is");
    std::cout << c.reliabilityRate();

    std::cout << "==================\n";
    StateCompany c1("FMI", 3);
    std::cout << c1.reliabilityRate();
    c1.perform("Learn algebra");
    c1.perform("Learn coding");
    c1.perform("Learn where the hot water is");
    std::cout << c1.reliabilityRate();

    Company** companies = new Company*[2];

    companies[0] = &c;
    companies[1] = &c1;

    Consortium cons1;

    cons1.perform("Learn algebra");
    cons1.perform("Learn coding");

    std::cout << cons1.reliabilityRate();

    Consortium cons2("Nashta firma", companies, 2);

    cons2.perform("Learn algebra");
    cons2.perform("Learn coding");
    cons2.perform("Learn where the hot water is");
    cons2.perform("New task 1");
    cons2.perform("New task 2");
    cons2.perform("New task 3");

    // std::cout << cons1.reliabilityRate();
    // std::cout << cons2.reliabilityRate();
    std::cout << cons2.reliabilityRate();
}