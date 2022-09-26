#include <iostream>
#include <string>

int main(int ac, char **av)
{
    int i;
    int j;
    std::string str;

    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    if (ac >= 2)
    {
        j = 1;
        while (av[j])
        {
            i = -1;
            while (av[j][++i])
                str += toupper(av[j][i]);
            ++j;
        }
        std::cout << str << std::endl;
    }
    return (0);
}