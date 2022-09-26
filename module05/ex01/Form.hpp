#ifndef FORM_HPP
#define FORM_HPP

#include "classes.hpp"

class Form
{
    private:

        std::string const    _name;
        bool                _isSigned;
        int const           _gradeToSign;
        int const           _gradeToExec;

    public:
    
        Form();
        ~Form();
        Form(std::string name, int toSign, int toExec);
        Form(Form & src);
        Form& operator=(Form & rhs);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Grade is too high.");
                }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Grade is too low.");
                }
        };

        std::string     getName() const;
        bool            getIsSigned() const;
        int             getToSign() const;
        int             getToExec() const;
        void            beSigned(Bureaucrat & src);

};

std::ostream &  operator<<(std::ostream & o, Form & src);

#endif