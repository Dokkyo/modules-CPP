#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap Constructor Called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap Constructor Called with name" << name << std::endl;
}

ScavTrap::ScavTrap(ScavTrap & src) : ClapTrap()
{
    *this = src;

    return;
}

ScavTrap& ScavTrap::operator=(ScavTrap & rhs)
{
    this->_name = rhs.getName();
    this->_hitPoints = rhs.getHitPoints();
    this->_EnergyPoints = rhs.getEnergypoints();
    this->_AttackDamage = rhs.getAttackDamage();

    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor Called" << std::endl;
}

void    ScavTrap::attack(const std::string& target)
{
    if (this->_EnergyPoints > 0 && this->_hitPoints > 0)
    {
        std::cout << "ScavTrap " << this->_name;
        std::cout << " attacks " << target;
        std::cout << " causing " << this->_AttackDamage;
        std::cout << " points of damage!" << std::endl;
        this->_EnergyPoints -= 1;
    }
    else if (this->_hitPoints <= 0)
        std::cout << "is Dead." << std::endl;
    else
        std::cout << "Missing energy." << std::endl;
}

void    ScavTrap::guardGate() const
{
    std::cout << this->_name << " turn into Gate keeper mode !" << std::endl;
}
