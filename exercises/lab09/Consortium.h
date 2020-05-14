#pragma once
#include "Company.h"

class Consortium : public Company
{
private:
    Company **companies;
    size_t companiesNum;
    void clear();
    void copy(const Consortium &);
    size_t getCompanyWithLeastTasks();

public:
    Consortium();
    Consortium(const std::string &, Company **const, const size_t);
    Consortium(const Consortium &);
    Consortium &operator=(const Consortium &);
    ~Consortium();

    bool perform(std::string);
};