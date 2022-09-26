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
        void    setName(std::string name);
        //Zombie* zombieHorde(int N, std::string name);

    private:
        std::string _name;
};

Zombie *zombieHorde(int N, std::string name);

#endif