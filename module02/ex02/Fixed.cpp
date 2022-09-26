#include "Fixed.hpp"

int const   Fixed::_bit = 8;

Fixed::Fixed() : _value(0)
{
    return;
}

Fixed::Fixed(int nbr)
{
    this->_value = nbr << this->_bit;

    return;
}

Fixed::Fixed(float const nbr)
{
    this->_value = roundf(nbr * (1 << this->_bit));

    return;
}

Fixed::~Fixed()
{
    return;
}

Fixed::Fixed(Fixed const & src)
{
    *this = src;

    return;
}

Fixed &     Fixed::operator=(Fixed const & rhs) 
{
    if (this != &rhs)
        this->_value = rhs.getRawBits();

    return (*this);
}

bool         Fixed::operator>(Fixed const & rhs) const
{
    return (this->_value > rhs._value);
}

bool         Fixed::operator<(Fixed const & rhs) const
{
    return (this->_value < rhs._value);
}

bool         Fixed::operator>=(Fixed const & rhs) const
{
    return (this->_value >= rhs._value);
}

bool         Fixed::operator<=(Fixed const & rhs) const
{
    return (this->_value <= rhs._value);
}

bool         Fixed::operator==(Fixed const & rhs) const
{
    return (this->_value == rhs._value);
}

bool         Fixed::operator!=(Fixed const & rhs) const
{
    return (this->_value != rhs._value);
}

Fixed       Fixed::operator+(Fixed const & rhs) const
{
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed       Fixed::operator-(Fixed const & rhs) const
{
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed       Fixed::operator*(Fixed const & rhs) const
{
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed       Fixed::operator/(Fixed const & rhs) const
{
    return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed &     Fixed::operator++()
{
    this->_value++;

    return(*this);
}

Fixed       Fixed::operator++(int)
{
    Fixed   before(*this);

    this->_value++;

    return(before);
}

Fixed &     Fixed::operator--()
{
    this->_value--;

    return(*this);
}

Fixed       Fixed::operator--(int)
{
    Fixed   before(*this);

    this->_value--;

    return(before);
}

std::ostream &      operator<<(std::ostream & o, Fixed const & rhs)
{
    o << rhs.toFloat();

    return (o);
}

int         Fixed::getRawBits(void) const
{
    return (this->_value);
}

void        Fixed::setRawBits(int const raw)
{
    this->_value = raw;

    return;
}

float       Fixed::toFloat( void ) const
{
    return((float)this->_value / (1 << this->_bit));
}

int         Fixed::toInt( void ) const
{
    return(this->_value >> this->_bit);
}

Fixed &     Fixed::min(Fixed& nb1, Fixed& nb2)
{
    if (nb1._value < nb2._value)
        return (nb1);
    else
        return (nb2);
}

const Fixed &     Fixed::min(Fixed const & nb1, Fixed const & nb2)
{
    if (nb1._value < nb2._value)
        return (nb1);
    else
        return (nb2);
}

Fixed &     Fixed::max(Fixed & nb1, Fixed & nb2)
{
    if (nb1._value > nb2._value)
        return (nb1);
    else
        return (nb2);
}

const Fixed &     Fixed::max(Fixed const & nb1, Fixed const & nb2)
{
    if (nb1._value > nb2._value)
        return (nb1);
    else
        return (nb2);
}