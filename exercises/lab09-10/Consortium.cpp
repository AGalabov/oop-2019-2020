#include "Consortium.h"
#include <bits/stdc++.h>
#include <math.h>

Consortium::Consortium(const std::string name = "") : Company(name), companies(nullptr), companiesNum(0), arraySize(0)
{
}

Consortium::Consortium(const std::string &name, Company **const companies, const size_t size)
    : Company(name)
{
    this->companiesNum = size;
    size_t newArraySize = ceil(log2(size));
    this->arraySize = newArraySize;
    this->companies = new Company *[newArraySize];
    for (size_t i = 0; i < size; ++i)
    {
        this->companies[i] = companies[i]->clone();
    }
}

Consortium::Consortium(const Consortium &other)
{
    this->copy(other);
}

void Consortium::clear()
{
    for (size_t i = 0; i < this->companiesNum; ++i)
    {
        delete this->companies[i];
    }
    delete[] companies;
}

void Consortium::copy(const Consortium &other)
{
    this->name = other.name;
    this->tasksReceived = other.tasksReceived;
    this->successfulTasks = other.successfulTasks;
    this->companiesNum = other.companiesNum;
    this->arraySize = other.arraySize;
    this->companies = new Company *[other.arraySize];
    for (size_t i = 0; i < other.companiesNum; ++i)
    {
        this->companies[i] = other.companies[i]->clone();
    }
}

Consortium &Consortium::operator=(const Consortium &other)
{
    if (this != &other)
    {
        this->clear();
        this->copy(other);
    }
    return *this;
}

Consortium::~Consortium()
{
    this->clear();
}

size_t Consortium::getCompanyWithLeastTasks()
{
    int leastTasks = INT_MAX;
    size_t index = 0;
    for (size_t i = 0; i < this->companiesNum; ++i)
    {
        int currentTasks = this->companies[i]->getTasksReceived();
        if (currentTasks < leastTasks)
        {
            leastTasks = currentTasks;
            index = i;
        }
    }
    return index;
}

bool Consortium::perform(std::string task)
{
    this->tasksReceived++;
    if (this->companies)
    {
        std::cout << this->name << " is delegating task: " << task << std::endl;
        size_t index = getCompanyWithLeastTasks();
        bool companyDidTheTask = companies[index]->perform(task);
        if (companyDidTheTask)
        {
            this->successfulTasks++;
        }
        return companyDidTheTask;
    }
    std::cout << this->name << " cannot perform the task: " << task << std::endl;
    return false;
}

Company *Consortium::clone()
{
    return new Consortium(*this);
}

void Consortium::add(Company *other)
{
    if (companiesNum + 1 > arraySize)
    {
        resize();
    }
    companies[companiesNum++] = other->clone();
}

void Consortium::resize()
{
    if (arraySize == 0)
    {
        arraySize = 2;
        companies = new Company *[arraySize];
        return;
    }

    arraySize *= 2;
    Company **copy = new Company *[arraySize];

    for (size_t i = 0; i < companiesNum; i++)
    {
        copy[i] = companies[i];
    }

    delete[] companies;
    companies = copy;
}

void Consortium::remove(std::string name)
{
    size_t idxToDelete = -1;
    for (size_t i = 0; i < companiesNum; i++)
    {
        if (companies[i]->getName() == name)
        {
            idxToDelete = i;
        }
    }

    if (idxToDelete == -1)
    {
        std::cout << "Company with name: " << name << " not found" << std::endl;
        return;
    }

    Company *toDelete = companies[idxToDelete];
    companies[idxToDelete] = companies[--companiesNum];
    companies[companiesNum] = nullptr;
    delete toDelete;
}

void Consortium::printStatus(std::ostream &os) const
{
    os << "Consortium:" << name << " , count: " << companiesNum << " reliability rate: " << reliabilityRate() << std::endl;
    for (size_t i = 0; i < companiesNum; i++)
    {
        companies[i]->printStatus(os);
    }
}