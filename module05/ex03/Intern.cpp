#include "classes.hpp"

Intern::Intern()
{
    std::cout << "+Intern Constructor Called" << std::endl;
}

Intern::Intern(Intern & src)
{
    *this = src;
}

Intern&     Intern::operator=(Intern & rhs)
{
    (void)rhs;

    return (*this);
}

Intern::~Intern()
{
    std::cout << "-Intern Destructor Called" << std::endl;
}

AForm  *Intern::Shrubbery(std::string target) const
{
    return (new ShrubberyCreationForm(target));
}

AForm  *Intern::Robotomy(std::string target) const
{
    return (new RobotomyRequestForm(target));
}

AForm*  Intern::Presidential(std::string target) const
{
    return (new PresidentialPardonForm(target));
}

AForm   *Intern::makeForm(std::string name, std::string target)
{
    std::string     request[3] = {"shrubbery request", "robotomy request", "presidential request"};
    AForm           *form[3] = {Intern::Shrubbery(target), Intern::Robotomy(target), Intern::Presidential(target)};
    int             i;
    int             j;

    i = -1;
    j = -1;
    while (++i < 3)
    {
        if (request[i] == name)
        {
            std::cout << "Intern create " << name << "form." << std::endl;
            while (++j < 3)
            {
                if (j != i)
                    delete form[j];
            }
            return (form[i]);
        }
    }
    throw Intern::FormNotFoundException();
    return (NULL);
}