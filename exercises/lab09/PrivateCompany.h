#pragma once
#include "Company.h"

class PrivateCompany : public Company
{
private:
    int kWillFail;

public:
    PrivateCompany();
    PrivateCompany(const std::string &, const int);
    PrivateCompany(const PrivateCompany &);
    PrivateCompany &operator=(const PrivateCompany &);
    ~PrivateCompany();

    bool perform(std::string);
};