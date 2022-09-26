#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{

    private:

        int                 _value;
        static int const    _bit;

    public:

        Fixed();
        Fixed(int const nbr);
        Fixed(float const nbr);
        Fixed(Fixed const & src);
        ~Fixed();

        Fixed &     operator=(Fixed const & rhs);

        int         getRawBits(void) const;
        void        setRawBits(int const raw);
        float       toFloat( void ) const;
        int         toInt( void ) const;
};

std::ostream &      operator<<(std::ostream & o, Fixed const & rhs);

#endif