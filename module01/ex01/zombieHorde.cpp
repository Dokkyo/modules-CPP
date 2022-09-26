#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
    if (N > 0)
    {
        Zombie  *zombie = new Zombie[N];
        int     i = 0;

        while (i < N)
            zombie[i++].setName(name);
        return(zombie);
    }
    else
        std::cout << "Set a value > 0" << std::endl;
    
    return (NULL);
}
