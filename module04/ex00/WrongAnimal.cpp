#include "classes.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal & src)
{
    *this = src;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal & rhs)
{
    this->_type = rhs._type;

    return(*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void    WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal No sound here" << std::endl;
}

std::string     WrongAnimal::getType() const
{
    return (this->_type);
}