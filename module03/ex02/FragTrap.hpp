#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class FragTrap : public ClapTrap
{
    private:

    public:
    
        FragTrap();
        FragTrap(std::string name);
        FragTrap(FragTrap & src);
        FragTrap& operator=(FragTrap & rhs);
        ~FragTrap();

        void    attack(std::string const & target);
        void    highFivesGuys() const;
};



#endif