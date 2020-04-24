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

    // for(int i = 0; i< n; i++)
    // {
    //     entities[i]->attack(*entities[(i+1)%n]);
    // }

    for (int i = 0; i < n; i++)
    {
        entities[i]->printPretty(std::cout);
    }

    for (int i = 0; i < n; i++)
    {
        delete entities[i];
    }

    delete[] entities;

    return 0;
}