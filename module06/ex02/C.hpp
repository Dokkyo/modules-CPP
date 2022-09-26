#ifndef C_HPP
#define C_HPP

#include "Base.hpp"

class C : public Base
{
    public:

       ~C(){
        std::cout << "C Destructor called" << std::endl;
       }
};

#endif 