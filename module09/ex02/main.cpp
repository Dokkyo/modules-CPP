#include "PmergeMe.hpp"

int     main(int ac, char **av)
{
    if (ac > 1)
    {
        PmergeMe    pm;
        int         ret;

        ret = pm.SetContainers(ac, av);
        if (ret)
            std::cout << "Argument position " << ret << " is not a number or is negativ.\n";
        else
            pm.Display(ac, av);
    }
    else
        std::cout << "The program use a positive integer sequence as argument.";
    return 0;
}