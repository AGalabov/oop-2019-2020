#include "StateCompany.h"

StateCompany::StateCompany() : Company(), oneSuccessInK(20)
{
}

StateCompany::StateCompany(const std::string &name, const double kSucc)
    : Company(name), oneSuccessInK(kSucc)
{
}

StateCompany::StateCompany(const StateCompany &other) : Company(other)
{
    this->oneSuccessInK = other.oneSuccessInK;
}

StateCompany &StateCompany::operator=(const StateCompany &other)
{
    if (this != &other)
    {
        // CLEAR IF ANYTHING
        this->name = other.name;
        this->tasksReceived = other.tasksReceived;
        this->successfulTasks = other.successfulTasks;
        this->oneSuccessInK = other.oneSuccessInK;
    }
    return *this;
}

StateCompany::~StateCompany()
{
    // CLEAR IF ANYTHING
}

bool StateCompany::perform(std::string task)
{
    std::cout << this->name << " is performing task: " << task << std::endl;
    this->tasksReceived++;
    if (this->tasksReceived % this->oneSuccessInK == 0)
    {
        std::cout << "Task was performed successfully!\n";
        this->successfulTasks++;
        return true;
    }
    else
    {
        std::cout << "Performing the task failed!\n";
        return false;
    }
}

Company* StateCompany::clone(){
    return new StateCompany(*this);
}

void StateCompany::printStatus(std::ostream& os) const{
    os << "State company:" << name << " reliability rate: " << reliabilityRate() << std::endl;
}