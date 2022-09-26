#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat  a("Qwerty", 0);

        std::cout << a << std::endl;
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    Bureaucrat  b("Qwerty", 150);

    std::cout << b << std::endl;
    return (0);
}