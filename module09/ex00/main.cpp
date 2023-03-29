#include "BitcoinExchange.hpp"

int     main(int ac, char **av)
{
    int i;

    i = 0;
    if (ac == 2)
    {
        BitcoinExchange Bex(av[1]);

        if (Bex.open() == EXIT_SUCCESS)
        {
            if (Bex.fill() == EXIT_SUCCESS)
            {
                if (Bex.findAndPrint() == EXIT_SUCCESS)
                {
                    std::cout << "Program has Finished its execution.\n";
                }
            }
        }
    }
    else
        std::cout << "The program takes one argument.\n";
    return 0;
}