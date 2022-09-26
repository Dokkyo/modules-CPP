#include "classes.hpp"

Bureaucrat::Bureaucrat()
{
    std::cout << "Bureaucrat Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
    {
        std::cout << "+Bureaucrat" << " " << name;
        std::cout << " " << "Grade" << " " << grade << std::endl;
    }
}

Bureaucrat::Bureaucrat(Bureaucrat & src)
{
    *this = src;
}

Bureaucrat&     Bureaucrat::operator=(Bureaucrat & rhs)
{
    this->_name = rhs._name;
    this->_grade = rhs._grade;

    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "-Bureaucrat" << " " << this->_name << std::endl;
}

std::ostream &  operator<<(std::ostream &o, Bureaucrat & src)
{
    o << src.getName() << ", bureaucrat grade" << src.getGrade() << std::endl;

    return (o);
}

std::string     Bureaucrat::getName() const
{
    return (this->_name);
}

int             Bureaucrat::getGrade() const
{
    return (this->_grade);
}

void            Bureaucrat::upGrade()
{
    if (--this->_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else
    {
        std::cout << "Your grade has increased";
        std::cout << " " << this->getGrade() << std::endl;
    }
}

void            Bureaucrat::downGrade()
{
    if (++this->_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
    {
        std::cout << "Your grade has decreased";
        std::cout << " " << this->getGrade() << std::endl;
    }
}

void            Bureaucrat::signForm(AForm & src)
{
    if (src.getIsSigned() == false && this->getGrade() > src.getToSign())
    {
        std::cout << this->getName() << " " << "couldn't sign" << " " << src.getName() << " " << "because: ";
        src.beSigned(*this);
    }
    else if (src.getIsSigned() == true)
        std::cout << this->getName() << " " << "couldn't sign" << " " << src.getName() << " " << "because it's already signed.";
    else
    {
        src.beSigned(*this);
        std::cout << this->getName() << " " << "signed" << " " << src.getName() << std::endl;
    }
}

void            Bureaucrat::executeForm(AForm & src)
{
    if (src.getIsSigned() == false || this->getGrade() > src.getToExec())
    {
        std::cout << this->getName() << " " << "couldn't execute" << " " << src.getName() << " " << "because: ";
        src.execute(*this);
    }
    src.execute(*this);
    std::cout << this->getName() << " executed " << src.getName() << std::endl;
}