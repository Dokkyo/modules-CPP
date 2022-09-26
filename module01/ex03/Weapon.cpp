#include "Weapon.hpp"

Weapon::Weapon()
{
    std::cout << "Weapon has been called" << std::endl;
}

Weapon::Weapon(std::string str) : _type(str)
{
    std::cout << "Weapon has been called" << std::endl;
}

Weapon::~Weapon()
{
    std::cout << "Weapon has been destroyed" << std::endl;
}

std::string Weapon::getType() const
{
    return (this->_type);
}

void Weapon::setType(std::string str)
{
    this->_type = str;
}
