#include "classes.hpp"

Dog::Dog() : _type("Dog")
{
    this->brain = new Brain();
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(Dog & src) : AAnimal()
{
    std::cout << "Dog Copy constructor called" << std::endl;
    this->brain = new Brain();
    *this = src;
}

Dog& Dog::operator=(Dog & rhs)
{
    this->_type = rhs._type;
    *this->brain = *rhs.brain;

    return(*this);
}

Dog::~Dog()
{
    delete this->brain;
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

Brain*  Dog::getBrain() const
{
    return (this->brain);
}