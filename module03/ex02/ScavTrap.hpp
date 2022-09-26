#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class ScavTrap : public ClapTrap
{

    private:
        
    
    public:
        
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(ScavTrap & src);
        ScavTrap& operator=(ScavTrap & rhs);
        ~ScavTrap();

        void    guardGate() const;
        void    attack(std::string const & target);
};


#endif