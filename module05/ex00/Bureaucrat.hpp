#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat
{
    private:
    
        std::string   _name;
        int           _grade;

    public:
    
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(Bureaucrat & src);
        Bureaucrat& operator=(Bureaucrat & rhs);
        ~Bureaucrat();

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
        int             getGrade() const;

        void            upGrade();
        void            downGrade();
};

std::ostream &  operator<<(std::ostream & o, Bureaucrat & src);

#endif
