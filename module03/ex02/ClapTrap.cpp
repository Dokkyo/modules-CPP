#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap Constructor Called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : 
_name(name),
_hitPoints(100),
_EnergyPoints(100),
_AttackDamage(30)
{
    std::cout << "ClapTrap Constructor Called with name " << name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap & src)
{
    *this = src;

    return;
}

ClapTrap& ClapTrap::operator=(ClapTrap & rhs)
{
    if (this != &rhs)
    {
        this->_name = rhs.getName();
        this->_hitPoints = rhs.getHitPoints();
        this->_EnergyPoints = rhs.getEnergypoints();
        this->_AttackDamage = rhs.getAttackDamage();
    }
    
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor Called" << std::endl;
}

void    ClapTrap::attack(const std::string& target)
{
    if (this->_EnergyPoints > 0 && this->_hitPoints > 0)
    {
        std::cout << "ClapTrap " << this->_name;
        std::cout << " attacks " << target;
        std::cout << " causing " << this->_AttackDamage;
        std::cout << " points of damage!" << std::endl;
        this->_EnergyPoints -= 1;
    }
    else if (this->_hitPoints <= 0)
        std::cout << this->_name << " is Dead." << std::endl;
    else
        std::cout << "Missing energy." << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints > 0)
    {
        std::cout << this->_name;
        std::cout << " takes " << amount;
        std::cout << " points of damage !";
        this->_hitPoints -= amount;
        if (this->_hitPoints < 0)
            this->_hitPoints = 0;
        std::cout << " Life now : " << this->_hitPoints << std::endl;
    }
    else
        std::cout << this->_name << " is dead." << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_EnergyPoints > 0 && this->_hitPoints > 0)
    {
        std::cout << this->_name;
        std::cout << " gained " << amount;
        std::cout << " life points !" << std::endl;
        this->_EnergyPoints -= 1;
        this->_hitPoints += amount;
    }
    else if (this->_hitPoints <= 0)
        std::cout << this->_name << " is Dead." << std::endl;
    else
        std::cout << "Missing energy." << std::endl;

}


std::string     ClapTrap::getName() const
{
    return (this->_name);
}

int     ClapTrap::getHitPoints() const
{
    return (this->_hitPoints);
}

int     ClapTrap::getEnergypoints() const
{
    return (this->_EnergyPoints);
}

int     ClapTrap::getAttackDamage() const
{
    return (this->_AttackDamage);
}
