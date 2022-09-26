#include "Data.hpp"

Data::Data()
{
    std::cout << "Data constructor1 called" << std::endl;
}

Data::Data(int i, char c) : _i(i), _c(c)
{
    std::cout << "Data constructor2 called" << std::endl;
}

Data::~Data()
{
    std::cout << "Data Destructor called" << std::endl;
}

int     Data::getI() const
{
    return(this->_i);
}

char     Data::getC() const
{
    return(this->_c);
}