#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <vector>
#include <iostream>
#include <algorithm>

template<typename T>
void   easyfind(T container, int occur)
{
    typename T::iterator iter;
    iter = std::find(container.begin(), container.end(), occur);
    if(iter != container.end())
    {
        std::cout << occur << std::endl;
    }
    else
        std::cout << "No occurence." << std::endl;
}

#endif