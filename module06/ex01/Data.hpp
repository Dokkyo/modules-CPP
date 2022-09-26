#ifndef DATA_HPP
# define DATA_HPP

#include <stdint.h>
#include <iostream>

class Data
{
    private:

        int     _i;
        char    _c;

    public:
        
        Data();
        Data(int i, char c);
        ~Data();

        int     getI() const;
        char    getC() const;
};

#endif