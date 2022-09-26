#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl        instance;

    if (ac == 2)
        instance.complain(av[1]);
    
    return (0);
}