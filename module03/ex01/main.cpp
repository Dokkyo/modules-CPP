#include "ScavTrap.hpp"

int main()
{
    ClapTrap    a("O");
    ScavTrap    b("K");
    ScavTrap    c;

    c = b;
    int         i = 0;

    while (i++ < 4)
    {
        a.attack("K");
        b.takeDamage(a.getAttackDamage());
        std::cout << std::endl;
    }
    i = 0;
    b.guardGate();
    while (i++ < 6)
    {
        b.attack("O");
        a.takeDamage(b.getAttackDamage());
        std::cout << std::endl;
    }

    a.beRepaired(4);
    b.beRepaired(6);
    c.guardGate();
    return (0);
}