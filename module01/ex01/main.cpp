#include "Zombie.hpp"

int main()
{
    Zombie  *z1;
    int     i = 0;

    z1 = zombieHorde(10, "Zombie");

    while (i < 10)
        z1[i++].announce();

    delete [] z1;

    return (0);
}
