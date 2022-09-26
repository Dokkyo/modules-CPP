#ifndef CONV_HPP
#define CONV_HPP

#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip>

class Conv
{
    private:
    
        int             _i;
        double          _d;
        float           _f;
        char            _c;
        int             _ret;
        std::string     _str;
    
    public:

        Conv(std::string str);
        Conv(Conv & src);
        Conv &  operator=(Conv & rhs);
        ~Conv();

        int     isInteger(std::string str) const;
        int     isDouble(std::string str) const;
        int     isChar(std::string str) const;
        int     isFloat(std::string str) const;

        int     detectType();
        void    display() const;
};

#endif