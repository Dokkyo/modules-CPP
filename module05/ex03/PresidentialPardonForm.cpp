#include "classes.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : 
AForm("Presidential Pardon Form", 25, 5),
_target(target)
{
    std::cout << "+PresidentialPardonForm Constructor Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm & src) : AForm("Presidential Pardon Form", 72, 45)
{
    *this = src;
}

PresidentialPardonForm&     PresidentialPardonForm::operator=(PresidentialPardonForm & rhs)
{
    this->_target = rhs._target;

    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "-PresidentialPardonForm Destructor Called" << std::endl;
}

std::string     PresidentialPardonForm::getTarget() const
{
    return (this->_target);
}

void            PresidentialPardonForm::action(Bureaucrat const & executor)
{
    if (this->getIsSigned() == false)
        throw AForm::FormUnsignedException();
    else if (executor.getGrade() > this->getToExec())
        throw AForm::GradeTooLowException();
    else
    {
        std::cout << this->getTarget() << " has beed forgived by Zaphod Beeblebrox." << std::endl;
    }
}