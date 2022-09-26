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

        Fixed &         operator=(Fixed const & rhs);

        bool             operator>(Fixed const & rhs) const;
        bool             operator<(Fixed const & rhs) const;
        bool             operator>=(Fixed const & rhs) const;
        bool             operator<=(Fixed const & rhs) const;
        bool             operator==(Fixed const & rhs) const;
        bool             operator!=(Fixed const & rhs) const;

        Fixed           operator+(Fixed const & rhs) const;
        Fixed           operator-(Fixed const & rhs) const;
        Fixed           operator*(Fixed const & rhs) const;
        Fixed           operator/(Fixed const & rhs) const;

        Fixed &         operator++();
        Fixed           operator++(int);
        Fixed &         operator--();
        Fixed           operator--(int);

        int             getRawBits(void) const;
        void            setRawBits(int const raw);
        float           toFloat( void ) const;
        int             toInt( void ) const;

        static Fixed &  min(Fixed& nb1, Fixed& nb2);

        static const Fixed &  min(Fixed const & nb1, Fixed const & nb2);

        static Fixed &  max(Fixed& nb1, Fixed& nb2);

        static const Fixed &  max(Fixed const & nb1, Fixed const & nb2);
};

std::ostream &      operator<<(std::ostream & o, Fixed const & rhs);

#endif