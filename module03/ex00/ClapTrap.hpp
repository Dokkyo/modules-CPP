#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    private:

        std::string     _name;
        int             _hitPoints;
        int             _EnergyPoints;
        int             _AttackDamage;

    public:
        
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(ClapTrap & src);
        ClapTrap& operator=(ClapTrap & rhs);
        ~ClapTrap();

        void            attack(const std::string& target);
        void            takeDamage(unsigned int amount);
        void            beRepaired(unsigned int amount);
        std::string     getName();
        int    getHitPoints();
        int    getEnergypoints();
        int    getAttackDamage();
};

#endif