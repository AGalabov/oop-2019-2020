#include "PrivateCompany.h"

PrivateCompany::PrivateCompany(): Company(), kWillFail(2)
{
}

PrivateCompany::PrivateCompany(const std::string& name, const int k)
    : Company(name), kWillFail(k)
{
}

PrivateCompany::PrivateCompany(const PrivateCompany& other): Company(other)
{
    this -> kWillFail = other.kWillFail;
}

PrivateCompany& PrivateCompany::operator=(const PrivateCompany& other)
{
    if(this != &other)
    {
        // CLEAR IF ANYTHING
        this -> name = other.name;
        this -> tasksReceived = other.tasksReceived;
        this -> successfulTasks = other.successfulTasks;
        this -> kWillFail = other.kWillFail;
    }
    return *this;
}

PrivateCompany::~PrivateCompany()
{
    // CLEAR IF ANYTHING
}

bool PrivateCompany::perform(std::string task)
{
    std::cout << this -> name << " is performing task: " << task << std::endl; 
    this -> tasksReceived++;
    if(this -> tasksReceived % this -> kWillFail != 0)
    {
        this -> successfulTasks++;
        std::cout <<  "Task was performed successfully!\n";
        return true;
    } else {
        std::cout <<  "Performing the task failed!\n";
        return false;
    }
}