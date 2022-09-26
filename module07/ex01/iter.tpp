#include <iostream>
#include <string>
#include <iomanip>

template <typename T>
void   iter(T *tab, T size, T&(add)(T&))
{
    int i = -1;
    if (tab)
        while (++i < size)
            std::cout << std::fixed << std::setprecision(1) << "Tab element " << i << ": " << add(tab[i]) << std::endl;
}

template <typename U>
U & add(U & elem)
{
    elem += 1;
    return(elem);
}