#include "classes.hpp"

WrongCat::WrongCat() : _type("WrongCat")
{
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat & src)
{
    *this = src;
}

WrongCat& WrongCat::operator=(WrongCat & rhs)
{
    this->_type = rhs._type;

    return(*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

void    WrongCat::makeSound() const
{
    std::cout << "Meuuh" << std::endl;
}

std::string     WrongCat::getType() const
{
    return (this->_type);
}