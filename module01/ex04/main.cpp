#include "Winner.hpp"

int main(int ac, char **av)
{
    if (ac == 4)
    {
        Winner  win;

        win.setValues(av[1], av[2], av[3]);
        win.newFile();
    }
    return (0);
}