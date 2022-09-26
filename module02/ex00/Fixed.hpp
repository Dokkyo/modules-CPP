#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{

    private:

        int                 _value;
        static int const    _bit;

    public:

        Fixed();
        Fixed(Fixed const & src);
        ~Fixed();

        Fixed &     operator=(Fixed const & rhs);

        int         getRawBits(void) const;
        void        setRawBits(int const raw);
};


#endif