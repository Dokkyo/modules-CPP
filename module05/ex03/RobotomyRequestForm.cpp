#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : 
AForm("Robotomy Request Form", 72, 45),
_target(target)
{
    std::cout << "+RobotomyRequestForm Constructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm & src) : AForm("RobotomyRequestForm", 72, 45)
{
    *this = src;
}

RobotomyRequestForm&     RobotomyRequestForm::operator=(RobotomyRequestForm & rhs)
{
    this->_target = rhs._target;

    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "-RobotomyRequestForm Destructor Called" << std::endl;
}

std::string     RobotomyRequestForm::getTarget() const
{
    return (this->_target);
}

void            RobotomyRequestForm::action(Bureaucrat const & executor)
{
    if (this->getIsSigned() == false)
        throw AForm::FormUnsignedException();
    else if (executor.getGrade() > this->getToExec())
        throw AForm::GradeTooLowException();
    else
    {
        std::cout << "Bzztttt....Bzzttttt..." << std::endl;
        srand (time(NULL));
        this->nbr = rand() % 2;
        if(this->nbr)
            std::cout << this->getTarget() << " has been robotomized." << std::endl;
        else
            std::cout << "Operation failed." << std::endl;
    }
}