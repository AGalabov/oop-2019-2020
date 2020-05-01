#pragma once
#include "Company.h"

class StateCompany: public Company
{
private:
    int oneSuccessInK;

public:
    StateCompany();
    StateCompany(const std::string&, const double);
    StateCompany(const StateCompany&);
    StateCompany& operator=(const StateCompany&);
    ~StateCompany();

    bool perform(std::string);
};