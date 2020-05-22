#include <iostream>
#include <exception>
#include <string>
#include <vector>

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

double divide(int num, int denom)
{
    if (denom == 0)
    {
        throw "Can not divide by 0";
    }

    return num / denom;
}

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

    // std::cout << divide(3, 2) << std::endl;

    // try
    // {
    //     std::cout << divide(3, 0) << std::endl;
    // }
    // catch (const char *err)
    // {
    //     std::cout << "Error occured: " << err;
    // }

    // try
    // {
    //     std::cout << veryErrorProne(5) << std::endl;
    //     std::cout << veryErrorProne(0) << std::endl;
    //     std::cout << veryErrorProne(1) << std::endl;
    //     std::cout << veryErrorProne(2) << std::endl;
    //     std::cout << veryErrorProne(42) << std::endl;
    //     std::cout << veryErrorProne(3) << std::endl;
    // }
    // catch (const char *charErr)
    // {
    //     std::cout << "Char Error occured: " << charErr;
    // }
    // catch (int intErr)
    // {
    //     std::cout << "Int Error occured: " << intErr;
    // }
    // catch (std::exception *stdErr)
    // {
    //     std::cout << "An Error occured: " << stdErr->what();
    // }
    // catch (...)
    // {
    //     std::cout << "A Generic Error occured: ";
    // }

    int n = 10;
    int *arr new int[n];

    std::vector<int> v(5);

    try
    {
        std::cout << v.at(6);
    }
    catch (std::out_of_range err)
    {
        std::cout << "Something went wrong dude\n"
                  << err.what();
    }

    std::cout << "\nI passed\n";

    return 0;
}