#include "EntityFactory.h"

#include <fstream>

void harm(Entity *subject, double dmg)
{
    subject->takeDamage(dmg);
}

int main()
{
    std::ifstream in("Entities.txt", std::ios::in);

    int n;
    in >> n;

    Entity **entities = new Entity *[n];

    for (int i = 0; i < n; i++)
    {
        entities[i] = EntityFactory::readEntity(in);
    }

    in.close();

    std::cout << "=============Read Entities=============\n";
    // Show what has been read from the file
    for (int i = 0; i < n; i++)
    {
        entities[i]->print(std::cout);
    }

    std::cout << "\n=============attack=============\n";
    // Use the virtual attack methods of Warrior and Mage
    for (int i = 0; i < n; i++)
    {
        entities[i]->attack(*entities[(i + 1) % n]);
    }

    std::cout << "\n=============Entities after battle=============\n";
    // Show the impact
    for (int i = 0; i < n; i++)
    {
        entities[i]->print(std::cout);
    }

    std::cout << "\n=============printVal=============\n";
    // Call the appropriate printVal methods
    for (int i = 0; i < n; i++)
    {
        entities[i]->printVal();
    }

    std::cout << "\n=============Destructors=============\n";
    // Call the appropriate destructors
    for (int i = 0; i < n; i++)
    {
        delete entities[i];
    }

    delete[] entities;

    return 0;
}