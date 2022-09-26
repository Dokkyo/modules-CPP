#ifndef B_HPP
#define B_HPP

#include "Base.hpp"

class B : public Base
{
    public:

       ~B(){
        std::cout << "B Destructor called" << std::endl;
       }
};

#endif