#include "classes.hpp"

int main()
{
    Bureaucrat  a("Mister côte de porc", 76);
    Form  b("Sauce bronzante barbecue", 75, 25);

    std::cout << std::endl;
    std::cout << b << std::endl;
    try
    {
        a.signForm(b);
        std::cout << b << std::endl;
    }
    catch(Form::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(Form::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    a.upGrade();
    std::cout << std::endl;

    try
    {
        a.signForm(b);
        std::cout << std::endl;
        std::cout << b << std::endl;
        a.signForm(b);
        std::cout << std::endl;
    }
    catch(Form::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(Form::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    return (0);
}