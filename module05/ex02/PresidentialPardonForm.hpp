#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "classes.hpp"

class PresidentialPardonForm : public AForm
{
    private:

        std::string     _target;

    public:

        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm & src);
        PresidentialPardonForm& operator=(PresidentialPardonForm & rhs);
        ~PresidentialPardonForm();

        virtual std::string     getTarget() const;
        virtual void            action(Bureaucrat const & executor);
};

#endif