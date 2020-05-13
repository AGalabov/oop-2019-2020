#include "EntityFactory.h"

#define binFile "entities.bin"

void harm(Entity *subject, double dmg)
{
    subject->takeDamage(dmg);
}


void writeEntitiesToBinFile(std::ofstream& out, Entity** entityCollection, int count){
    out.write((char*)&count,sizeof(count));

    for(int i = 0; i < count; i++){
        entityCollection[i] -> writeToBinFile(out);

        /*
        int type = entityCollection[i]->getType();
        if(type == Mage::type){
            out.write((char*)&type,sizeof(int));
            out.write((char*)entityCollection[i], sizeof(Mage));
        }
        else if(type == Warrior::type){
            out.write((char*)&type,sizeof(int));
            out.write((char*)entityCollection[i],sizeof(Warrior));
        }
        else{
            std::cout << "Unknown type" << std::endl;
        }
        */
    }
}


void readAndPrintEntitiesFromBinFile(std::ifstream& in){
    int count = -1;

    in.read((char*)&count, sizeof(count));
    std::cout << "\n Entities to be read: " << count << std::endl;

    Entity** entities = new Entity* [count];

    for(int i = 0; i < count; i++){
        entities[i] = EntityFactory::readEntityBin(in);
    }

    std::cout << "\n=============printVal=============\n";
    // Call the appropriate printVal methods
    for (int i = 0; i < count; i++)
    {
        //entities[i]->printVal();
        entities[i]->print(std::cout);
    }

    for (int i = 0; i < count; i++){
        delete entities[i];
    }

    delete[] entities;
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

    std::ofstream outFile;
    outFile.open(binFile,std::ios::out|std::ios::binary);

    if(!outFile){
        std::cout << "Error while opening file for writing" << std::endl;
    }
    else{
        std::cout <<" \n Writing to file " << binFile << "...";
        writeEntitiesToBinFile(outFile, entities, n);
        std::cout << "Done!" <<std::endl;
        outFile.close();

        std::ifstream inFile;
        inFile.open(binFile,std::ios::binary);

        if(!inFile){
            std::cout << "Error while opening file for writing" << std::endl;
        }
        else{
            std::cout << " \n Reading from file " << binFile << std::endl; 
            readAndPrintEntitiesFromBinFile(inFile);
        }
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