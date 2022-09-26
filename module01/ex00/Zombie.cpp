#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout << "Zombie Constructor called" << std::endl;
}

Zombie::Zombie(std::string str) : _name(str)
{
    std::cout << this->_name << " has been created" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << this->_name << " has been destroyed" << std::endl;
}

void    Zombie::announce()
{
    std::cout << this->_name << ": BraiiiiinnnnzzzzzZ.." << std::endl;
}
