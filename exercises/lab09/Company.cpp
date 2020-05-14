#include "Company.h"

Company::Company()
{
    this->name = "";
    this->tasksReceived = 0;
    this->successfulTasks = 0;
}

Company::Company(const std::string &name)
{
    this->name = name;
    this->tasksReceived = 0;
    this->successfulTasks = 0;
}

Company::Company(const Company &other)
{
    this->copy(other);
}

Company &Company::operator=(const Company &other)
{
    if (this != &other)
    {
        this->clear();
        this->copy(other);
    }
    return *this;
}

Company::~Company()
{
    this->clear();
}

std::string Company::getName() const
{
    return this->name;
}

void Company::setName(const std::string &name)
{
    this->name = name;
}

int Company::getTasksReceived() const
{
    return this->tasksReceived;
}

void Company::copy(const Company &other)
{
    this->name = other.name;
    this->tasksReceived = other.tasksReceived;
    this->successfulTasks = other.successfulTasks;
}

void Company::clear()
{
    // Clear any dynamically taken data
}

int Company::getSuccessfulTasks() const
{
    return this->successfulTasks;
}

double Company::reliabilityRate()
{
    if (this->tasksReceived == 0)
    {
        return 0;
    }
    return (double)successfulTasks / tasksReceived;
}