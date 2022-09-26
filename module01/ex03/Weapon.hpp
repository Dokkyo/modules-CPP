#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
    private:
    
        std::string _type;

    public:
        Weapon();
        Weapon(std::string str);
        ~Weapon();

        std::string getType() const;
        void        setType(std::string str);
};

#endif
