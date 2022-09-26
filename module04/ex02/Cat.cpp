#include "classes.hpp"

Cat::Cat() : _type("Cat")
{
    this->brain = new Brain();
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(Cat & src) : AAnimal()
{
    std::cout << "Cat Copy constructor called" << std::endl;
    this->brain = new Brain();
    *this = src;
}

Cat& Cat::operator=(Cat & rhs)
{
    this->_type = rhs._type;
    *this->brain = *rhs.brain;

    return(*this);
}

Cat::~Cat()
{
    delete this->brain;
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

Brain  *Cat::getBrain() const
{
    return (this->brain);
}