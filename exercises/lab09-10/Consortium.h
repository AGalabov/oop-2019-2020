#pragma once
#include "Company.h"

class Consortium: public Company
{
private:
    Company** companies;
    size_t companiesNum;
    size_t arraySize;
    void clear();
    void copy(const Consortium&);
    size_t getCompanyWithLeastTasks();

    void resize();

public:
    Consortium(const std::string);
    Consortium(const std::string&, Company** const, const size_t);
    Consortium(const Consortium&);
    Consortium& operator=(const Consortium&);
    ~Consortium();

    bool perform(std::string);

    Company* clone();

    void add(Company*);
    void remove(std::string);

    void printStatus(std::ostream&) const;
};