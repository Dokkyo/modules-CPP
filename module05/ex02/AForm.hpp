#ifndef FORM_HPP
#define FORM_HPP

#include "classes.hpp"

class AForm
{
    private:

        std::string const    _name;
        bool                _isSigned;
        int const           _gradeToSign;
        int const           _gradeToExec;

    public:

        AForm();
        AForm(std::string name, int toSign, int toExec);
        AForm(AForm & src);
        AForm& operator=(AForm & rhs);
        ~AForm();

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
        class FormUnsignedException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Form is unsigned.");
                }
        };

        virtual void        action(Bureaucrat const & executor) = 0;
        std::string         getName() const;
        bool                getIsSigned() const;
        int                 getToSign() const;
        int                 getToExec() const;
        void                beSigned(Bureaucrat & src);
        void                execute(Bureaucrat & executor);

};

std::ostream &  operator<<(std::ostream & o, AForm & src);

#endif