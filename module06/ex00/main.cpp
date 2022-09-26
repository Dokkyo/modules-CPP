#include "Conv.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return 0;
    else
    {
        Conv conv(av[1]);
        int i = 0;

        i = conv.detectType();
        if (i == 0)
            conv.display();
        else
            std::cout << "wtf ?" << std::endl;
    }

    return (0);
}