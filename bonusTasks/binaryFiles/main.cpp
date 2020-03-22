#include <fstream>
#include <iostream>
#include "Point.h"

Point::Point()
{
    this->x = 0;
    this->y = 0;
}

Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}

double Point::getX()
{
    return this->x;
}

double Point::getY()
{
    return this->y;
}

void Point::setX(double x)
{
    this->x = x;
}

void Point::setY(double y)
{
    this->y = y;
}

void Point::print()
{
    std::cout << "(" << this->x << ", " << this->y << ")\n";
}

int main()
{
    Point p1(42, 3.14);
    Point p2(12, 5);

    // Create and open an output binary file called "points.bin"
    std::ofstream outBinaryFile("./points.bin", std::ios::out | std::ios::binary);

    if (!outBinaryFile)
    {
        std::cout << "Error in opening file...\n";
        return -1;
    }

    // tellp shows the current position of the PUT pointer - where the next data will be written
    // By default starts at 0
    std::cout << "PUT Poistion: " << outBinaryFile.tellp() << std::endl;

    outBinaryFile.write((char *)&p1, sizeof(p1)); //sizeof function returns the size of an object/type

    // Write will automatically offset the PUT pointer by how many bytes were used
    // In this case sizeof(p1) = 16 = 2 * 8 because there are 2 double values stored in the class
    std::cout << "PUT Poistion: " << outBinaryFile.tellp() << std::endl;

    outBinaryFile.write((char *)&p2, sizeof(p2));

    std::cout << "PUT Poistion: " << outBinaryFile.tellp() << std::endl;

    outBinaryFile.close();

    Point p3;

    // Create and open an input binary file called "points.bin"
    std::ifstream inputBinaryFile("./points.bin", std::ios::in | std::ios::binary);

    if (!inputBinaryFile)
    {
        std::cout << "Error in opening file...\n";
        return -1;
    }

    // tellg shows the current position of the GET pointer - where the next data will be read from
    // By default starts at 0
    std::cout << "GET Poistion: " << inputBinaryFile.tellg() << std::endl;

    // seekg allows us to move the GET modifier to an absolute position or move it with desired
    // offset in any position. In  this case we move it with  sizeof(p3) = 16 bytes
    inputBinaryFile.seekg(1 * sizeof(p3));

    std::cout << "GET Poistion: " << inputBinaryFile.tellg() << std::endl;

    if (inputBinaryFile.read((char *)&p3, sizeof(p3)))
    { // in this case we will read the data for point p2 (because of seekg)
        std::cout << std::endl
                  << "Read point: ";
        p3.print();
        std::cout << std::endl;
    }
    else
    {
        // We may not be able to read - for example if we use seekg to put the pointer
        // in a position where no data was written - in this case anywhere beyond 32 bytes
        std::cout << "Error in reading data from file...\n";
        return -1;
    }

    // Read will automatically offset the PUT pointer by how many bytes were used
    std::cout << "GET Poistion: " << inputBinaryFile.tellg() << std::endl;

    inputBinaryFile.close();

    return 0;
}
