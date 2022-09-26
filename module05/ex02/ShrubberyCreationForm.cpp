#include "classes.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : 
AForm("Shrubbery Creation Form", 145, 137),
_target(target)
{
    std::cout << "+ShrubberyCreationForm Constructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm & src) : AForm("Shrubbery Creation Form", 145, 137)
{
    *this = src;
}

ShrubberyCreationForm&     ShrubberyCreationForm::operator=(ShrubberyCreationForm & rhs)
{
    this->_target = rhs._target;

    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "-ShrubberyCreationForm Destructor Called" << std::endl;
}

std::string     ShrubberyCreationForm::getTarget() const
{
    return (this->_target);
}

void            ShrubberyCreationForm::action(Bureaucrat const & executor)
{
    if (this->getIsSigned() == false)
        throw AForm::FormUnsignedException();
    else if (executor.getGrade() > this->getToExec())
        throw AForm::GradeTooLowException();
    else
    {
        this->_file = this->getTarget() + "_shrubbery";
        std::ofstream ofs(this->_file.c_str());

        ofs << "                       ||                        " << std::endl;
        ofs << "                       WW                        " << std::endl;
        ofs << "                      WWWW                       " << std::endl;
        ofs << "                     WWWWWW                      " << std::endl;
        ofs << "                    WWWWWWWW                     " << std::endl;
        ofs << "                   WWWWWWWWWW                    " << std::endl;
        ofs << "                  \\|/||||||||\\| /                " << std::endl;
        ofs << "                 \\ /|/||||||||\\|\\ /              " << std::endl;
        ofs << "            \\ / |/||||||||\\| \\ /                 " << std::endl;
        ofs << "_______________/__|/||||||||\\|__\\_/______________" << std::endl;
        ofs << "                 _*/wwwwwwww\\*_                  " << std::endl;
        ofs << "                | / \\_______/ \\|                 " << std::endl;
        ofs << "                | \\ \\  |||  / /|                 " << std::endl;
        ofs << "                |    | |||  |  |                 " << std::endl;
        ofs << "                |  | |      | ||                 " << std::endl;
    }
}