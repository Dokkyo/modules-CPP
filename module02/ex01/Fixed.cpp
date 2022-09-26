#include "Fixed.hpp"

int const   Fixed::_bit = 8;

Fixed::Fixed() : _value(0)
{
    std::cout << "Default Constructor Called" << std::endl;

    return;
}

Fixed::Fixed(int nbr)
{
    std::cout << "Int Constructor Called" << std::endl;
    this->_value = nbr << this->_bit;

    return;
}

Fixed::Fixed(float const nbr)
{
    std::cout << "Float Constructor Called" << std::endl;
    this->_value = roundf(nbr * (1 << this->_bit));

    return;
}

Fixed::~Fixed()
{
    std::cout << "Destructor Called" << std::endl;

    return;
}

Fixed::Fixed(Fixed const & src)
{
    std::cout << "Copy Constructor Called" << std::endl;
    *this = src;

    return;
}

Fixed &     Fixed::operator=(Fixed const & rhs) 
{
    std::cout << "Copy assignment operator called" << std::endl;

    if (this != &rhs)
        this->_value = rhs.getRawBits();

    return (*this);
}

std::ostream &      operator<<(std::ostream & o, Fixed const & rhs)
{
    o << rhs.toFloat();

    return (o);
}

int         Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function Called" << std::endl;

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
