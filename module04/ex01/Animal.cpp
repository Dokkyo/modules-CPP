#include "classes.hpp"

Animal::Animal() : _type("Animal")
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(Animal & src)
{
    std::cout << "Animal Copy constructor called" << std::endl;
    *this = src;
}

Animal& Animal::operator=(Animal & rhs)
{
    this->_type = rhs._type;

    return(*this);
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

void    Animal::makeSound() const
{
    std::cout << "Animal No sound here" << std::endl;
}

std::string     Animal::getType() const
{
    return (this->_type);
}