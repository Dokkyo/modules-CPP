#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap    a("Pierre");
    ScavTrap    b("Paul");
    FragTrap    c("Jacques");

    int         i = 0;

    while (i++ < 3)
    {
        a.attack("Paul");
        b.takeDamage(a.getAttackDamage());
        std::cout << std::endl;
    }
    i = 0;
    b.guardGate();
    while (i++ < 4)
    {
        b.attack("Pierre");
        a.takeDamage(b.getAttackDamage());
        std::cout << std::endl;
    }

    c.highFivesGuys();
    a.attack("Jacques");
    b.attack("Jacques");
    c.takeDamage(a.getAttackDamage());

    c.attack("Paul");
    b.takeDamage(c.getAttackDamage());
    
    a.beRepaired(4 * 30);
    b.beRepaired(4 * 30);
    c.beRepaired(1 * 30);

    std::cout << a.getName() << ":" << a.getHitPoints() << std::endl;
    std::cout << b.getName() << ":" << b.getHitPoints() << std::endl;
    std::cout << c.getName() << ":" << c.getHitPoints() << std::endl;

    return (0);
}