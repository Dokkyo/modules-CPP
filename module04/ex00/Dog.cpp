#include "classes.hpp"

Dog::Dog() : _type("Dog")
{
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(Dog & src)
{
    *this = src;
}

Dog& Dog::operator=(Dog & rhs)
{
    this->_type = rhs._type;

    return(*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

void    Dog::makeSound() const
{
    std::cout << "WAF" << std::endl;
}

std::string     Dog::getType() const
{
    return (this->_type);
}