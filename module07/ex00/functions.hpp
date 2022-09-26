#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <string>

template <typename T>
T   max(T const & x, T const & y)
{
    return ((x > y) ?  x : y);
}

template <typename Z>
Z   min(Z const & x, Z const & y)
{
    return ((x < y) ?  x : y);
}

template <typename P>
void   swap(P & x, P & y)
{
    P tmp;

    tmp = x;
    x = y;
    y = tmp;

}

#endif