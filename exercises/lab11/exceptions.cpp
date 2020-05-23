#include <iostream>
#include <exception>
#include <string>
#include <vector>


// Define a custom exception - TASK 3
class MyException : public std::exception
{
private:
    std::string errorMsg;

public:
    MyException(const char *errMsg) : errorMsg(errMsg)
    {
    }

    virtual const char *what() const throw()
    {
        return errorMsg.c_str();
    }
};

// TASK 1
double divide(int num, int denom)
{
    if (denom == 0)
    {
        throw "Can not divide by 0";
    }

    return num / denom;
}

// TASKS 2 && 3
int veryErrorProne(int a)
{
    if (a == 0)
    {
        throw "Can not use 0";
    }
    if (a == 1)
    {
        throw 1;
    }
    if (a == 3)
    {
        throw false;
    }
    if (a == 42)
    {
        throw new MyException("42 is the meaning of life");
    }
    return a;
}

int main()
{
    std::cout << "\n-----------------TASK 1-----------------\n";
    std::cout << divide(3, 2) << std::endl;

    try
    {
        std::cout << divide(3, 0) << std::endl;
    }
    catch (const char *err)
    {
        std::cout << "Error occured: " << err << std::endl;
    }

    std::cout << "\n-----------------TASK 2-----------------\n";

    try
    {
        std::cout << veryErrorProne(5) << std::endl;
        std::cout << veryErrorProne(0) << std::endl; // throws const char*
        std::cout << veryErrorProne(1) << std::endl; // throws int
        std::cout << veryErrorProne(2) << std::endl;
        std::cout << veryErrorProne(3) << std::endl; // throws bool
    }
    catch (const char *charErr)
    {
        std::cout << "Char Error occurred: " << charErr << std::endl;
    }
    catch (int intErr)
    {
        std::cout << "Int Error occurred: " << intErr << std::endl;
    }
    catch (bool boolErr)
    {
        std::cout << "Bool Error occurred: " << boolErr << std::endl;
    }
    catch (...)
    {
        std::cout << "A Generic Error occurred: " << std::endl;
    }


    std::cout << "\n-----------------TASK 3-----------------\n";

    try
    {
        std::cout << veryErrorProne(5) << std::endl;
        std::cout << veryErrorProne(42) << std::endl; // throws MyException
    }
    catch (std::exception *stdErr)
    {
        std::cout << "A Custom Error occurred: " << stdErr->what();
    }

    std::cout << "\n-----------------TASK 4-----------------\n";

    std::vector<int> v(5);
    try
    {
        std::cout << v.at(6); // throws std::out_of_range
    }
    catch (std::out_of_range err)
    {
        std::cout << "Out of ranger error occurred\n"
                  << err.what() << std::endl;
    }

    std::cout << "\nProgram will finish!\n";

    return 0;
}