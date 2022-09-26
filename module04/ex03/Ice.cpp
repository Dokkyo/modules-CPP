#include "classes.hpp"

Ice::Ice()
{
    std::cout << "Ice Constructor Called" << std::endl;
}

Ice::Ice(std::string const & type) : _type(type)
{
    std::cout << "Ice Constructor Called with type : " << type << std::endl;
}

Ice::Ice(Ice & src) : AMateria()
{
    std::cout << "Ice Copy constructor called" << std::endl;
    *this = src;
}

Ice& Ice::operator=(Ice & rhs)
{
    this->_type = rhs._type;

    return(*this);
}

Ice::~Ice()
{
    std::cout << "Ice Destructor Called" << std::endl;
}