#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap Constructor Called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap Constructor Called with name " << name << std::endl;
}

FragTrap::FragTrap(FragTrap & src) : ClapTrap()
{
    *this = src;

    return;
}

FragTrap& FragTrap::operator=(FragTrap & rhs)
{
    this->_name = rhs.getName();
    this->_hitPoints = rhs.getHitPoints();
    this->_EnergyPoints = rhs.getEnergypoints();
    this->_AttackDamage = rhs.getAttackDamage();

    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor Called" << std::endl;
}

void    FragTrap::attack(const std::string& target)
{
    if (this->_EnergyPoints > 0 && this->_hitPoints > 0)
    {
        std::cout << "FragTrap " << this->_name;
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

void    FragTrap::highFivesGuys() const
{
    std::cout << this->_name << ": High me five guys !" << std::endl;
}
