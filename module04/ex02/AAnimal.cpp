#include "classes.hpp"

AAnimal::AAnimal() : _type("AAnimal")
{
    std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal & src)
{
    std::cout << "AAnimal Copy constructor called" << std::endl;
    *this = src;
}

AAnimal& AAnimal::operator=(AAnimal & rhs)
{
    this->_type = rhs._type;

    return(*this);
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal destructor called" << std::endl;
}

std::string     AAnimal::getType() const
{
    return (this->_type);
}