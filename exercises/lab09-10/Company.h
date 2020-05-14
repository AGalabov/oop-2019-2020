#pragma once
#include <iostream>
#include <string>

class Company
{
private:
    void copy(const Company &);
    void clear();

protected:
    std::string name;
    int tasksReceived;
    int successfulTasks;

public:
    Company();
    Company(const std::string &);
    Company(const Company &);
    Company &operator=(const Company &);
    virtual ~Company();

    std::string getName() const;
    void setName(const std::string &);
    int getTasksReceived() const;
    int getSuccessfulTasks() const;

    virtual bool perform(std::string) = 0;
    double reliabilityRate() const;

    virtual Company *clone() = 0;
    virtual void printStatus(std::ostream &) const = 0;

    friend std::ostream &operator<<(std::ostream &, const Company &);
};