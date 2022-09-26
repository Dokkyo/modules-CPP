#include "classes.hpp"

Cure::Cure()
{
    std::cout << "Cure Constructor Called" << std::endl;
}

Cure::Cure(std::string const & type) : _type(type)
{
    std::cout << "Cure Constructor Called with type : " << type << std::endl;
}

Cure::Cure(Cure & src) : AMateria()
{
    std::cout << "Cure Copy constructor called" << std::endl;
    *this = src;
}

Cure& Cure::operator=(Cure & rhs)
{
    this->_type = rhs._type;

    return(*this);
}

Cure::~Cure()
{
    std::cout << "Cure Destructor Called" << std::endl;
}