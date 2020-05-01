#include "Consortium.h"
#include<bits/stdc++.h>

Consortium::Consortium(): Company(), companies(nullptr), companiesNum(0)
{
}

Consortium::Consortium(const std::string& name, Company** const companies, const size_t size)
    : Company(name)
{
    this -> companiesNum = size;
    this -> companies = new Company*[size];
    for(size_t i=0; i<size; ++i)
    {
        this -> companies[i] = new Company(companies[i]);
    }
}

Consortium::Consortium(const Consortium& other)
{
    this -> copy(other);
}

void Consortium::clear()
{
    for(size_t i=0; i<this -> companiesNum; ++i)
    {
        delete this -> companies[i];
    }
    delete[] companies;
}

void Consortium::copy(const Consortium& other)
{
    this -> name = other.name;
    this -> tasksReceived = other.tasksReceived;
    this -> successfulTasks = other.successfulTasks;
    this -> companiesNum = other.companiesNum;
    this -> companies = new Company*[other.companiesNum];
    for(size_t i=0; i<other.companiesNum; ++i)
    {
        this -> companies[i] = other.companies[i];
    }
}

Consortium& Consortium::operator=(const Consortium& other)
{
    if(this != &other)
    {
        this -> clear();
        this -> copy(other);
    }
    return *this;
}

Consortium::~Consortium()
{
    this -> clear();
}

size_t Consortium::getCompanyWithLeastTasks()
{
    int leastTasks = INT_MAX;
    size_t index = 0;
    for(size_t i=0; i<this -> companiesNum; ++i)
    {
        int currentTasks = this -> companies[i] -> getTasksReceived();
        if(currentTasks < leastTasks)
        {
            leastTasks = currentTasks;
            index = i;
        }
    }
    return index;
}

bool Consortium::perform(std::string task)
{
    this -> tasksReceived++;
    if(this -> companies)
    {
        std::cout << this -> name << " is delegating task: " << task << std::endl;
        size_t index = getCompanyWithLeastTasks();
        bool companyDidTheTask = companies[index] -> perform(task);
        if(companyDidTheTask)
        {
            this -> successfulTasks++;
        }
        return companyDidTheTask;
    }
    std::cout << this -> name << " cannot perform the task: " << task << std::endl;
    return false;
}