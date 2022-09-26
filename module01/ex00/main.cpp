#include "Zombie.hpp"

int main()
{
    Zombie  z2("Stack");
    Zombie  *z1;

    z2.announce();
    randomChump("Stack aussi");
    z1 = newZombie("Heap");
    z1->announce();

    delete z1;
    return (0);
}