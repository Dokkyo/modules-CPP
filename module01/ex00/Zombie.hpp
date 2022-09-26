#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {

    public:

        Zombie();
        Zombie(std::string str);
        ~Zombie();

        void    announce(void);

    private:

        std::string _name;
};

Zombie* newZombie( std::string name );
void    randomChump( std::string name );

#endif