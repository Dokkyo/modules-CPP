#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "classes.hpp"

class RobotomyRequestForm : public AForm
{
    private:

        std::string     _target;
        int             nbr;

    public:

        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm & src);
        RobotomyRequestForm& operator=(RobotomyRequestForm & rhs);
        virtual ~RobotomyRequestForm();

        virtual std::string     getTarget() const;
        virtual void            action(Bureaucrat const & executor);
};


#endif