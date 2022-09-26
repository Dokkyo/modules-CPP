#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <string>

class Base
{
    public:

       virtual ~Base(){
        std::cout << "Base Destructor called" << std::endl;
       }
};

#endif