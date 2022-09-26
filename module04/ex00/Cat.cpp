#include "classes.hpp"

Cat::Cat() : _type("Cat")
{
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(Cat & src)
{
    *this = src;
}

Cat& Cat::operator=(Cat & rhs)
{
    this->_type = rhs._type;

    return(*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

void    Cat::makeSound() const
{
    std::cout << "Miaou" << std::endl;
}

std::string     Cat::getType() const
{
    return (this->_type);
}