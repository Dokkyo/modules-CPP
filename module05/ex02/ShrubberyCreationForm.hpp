#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "classes.hpp"

class ShrubberyCreationForm : public AForm
{
    private:

        std::string     _target;
        std::string     _file;

    public:

        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm & src);
        ShrubberyCreationForm& operator=(ShrubberyCreationForm & rhs);
        ~ShrubberyCreationForm();

        virtual std::string     getTarget() const;
        virtual void            action(Bureaucrat const & executor);
};

#endif