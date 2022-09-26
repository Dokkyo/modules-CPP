#include "classes.hpp"

int main()
{
    Bureaucrat              a("Mister côte de porc", 5);
    ShrubberyCreationForm   b("jardin");
    RobotomyRequestForm     c("Robotomie");
    PresidentialPardonForm  d("Robert");
    Intern                  random;
    AForm                   *rrf;


    std::cout << std::endl;

    try
    {
        std::cout << b << std::endl;
        a.signForm(b);
        a.executeForm(b);
    }
    catch(AForm::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(AForm::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(AForm::FormUnsignedException &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout<< "------------------------------------------" << std::endl;
    std::cout << std::endl;

    try
    {
        std::cout << c << std::endl;
        a.signForm(c);
        a.executeForm(c);
    }
    catch(AForm::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(AForm::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(AForm::FormUnsignedException &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout<< "------------------------------------------" << std::endl;
    std::cout << std::endl;

    try
    {
        rrf = random.makeForm("robotomy request", "listener");
        std::cout << d << std::endl;
        a.signForm(*rrf);
        a.executeForm(*rrf);
        a.signForm(d);
        a.executeForm(d);
    }
    catch(AForm::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(AForm::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(AForm::FormUnsignedException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(Intern::FormNotFoundException &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout<< "==========================================" << std::endl;
    std::cout << b << std::endl;
    std::cout << std::endl;
    std::cout << c << std::endl;
    std::cout << std::endl;
    std::cout << d << std::endl;


    delete rrf;
    std::cout << std::endl;
    std::cout << std::endl;
    return (0);
}
