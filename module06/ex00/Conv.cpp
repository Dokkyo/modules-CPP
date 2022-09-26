#include "Conv.hpp"

Conv::Conv(std::string str) : _str(str)
{
    std::cout << "Conv Constructor Called" << std::endl;
}

Conv::Conv(Conv & src)
{
    *this = src;
}

Conv & Conv::operator=(Conv & rhs)
{
    this->_i = rhs._i;
    this->_d = rhs._d;
    this->_f = rhs._f;
    this->_c = rhs._c;

    return (*this);
}

Conv::~Conv()
{
    std::cout << "Conv Destructor Called" << std::endl;
}

int     Conv::isChar(std::string str) const
{
    if (str.size() == 1 && (str[0] < 48 || str[0] > 57))
        return 2;
    return 0;
}

int     Conv::isDouble(std::string str) const
{
    size_t  idx;
    int     dot;

    if (str == "-inf" || str == "+inf" || str == "nan")
        return 1;
    dot = 0;
    for(idx = 0; isdigit(str[0]) && (isdigit(str[idx]) || str[idx] == '.'); idx++)
        if (str[idx] == '.')
            dot++;
    if (idx == str.size() && dot == 1)
        return 2;

    return 0;
}

int     Conv::isFloat(std::string str) const
{
    size_t  idx;
    int     dot;

    if (str == "-inff" || str == "+inff" || str == "nanf")
        return 1;
    dot = 0;
    for(idx = 0; isdigit(str[0]) && (isdigit(str[idx]) || str[idx] == '.'); idx++)
        if (str[idx] == '.')
            dot++;
    if (idx == str.size() - 1 && str[idx] == 'f' && dot == 1)
       return 2;
    return 0;
}

int     Conv::isInteger(std::string str) const
{
    size_t     idx;

    for(idx = 0; isdigit(str[idx]); idx++)
        ;
    if (idx == str.size())
        return 2;
    return 0;
}

int    Conv::detectType()
{
    if ((this->_ret = isChar(this->_str)))
    {
        this->_c = this->_str[0];
        this->_i = static_cast<int>(this->_c);
        this->_f = static_cast<float>(this->_c);
        this->_d = static_cast<double>(this->_c);
        return (0);
    }
    else if((this->_ret = isDouble(this->_str)))
    {
        this->_d = strtod(this->_str.c_str(), NULL);
        this->_c = static_cast<char>(this->_d);
        this->_i = static_cast<int>(this->_d);
        this->_f = static_cast<float>(this->_d);
        return (0);
    }
    else if((this->_ret = isFloat(this->_str)))
    {
        this->_f = strtof(this->_str.c_str(), NULL);
        this->_c = static_cast<char>(this->_f);
        this->_i = static_cast<int>(this->_f);
        this->_d = static_cast<double>(this->_f);
        return (0);
    }
    else if((this->_ret = isInteger(this->_str)))
    {
        this->_i = atoi(this->_str.c_str());
        this->_c = static_cast<char>(this->_i);
        this->_d = static_cast<double>(this->_i);
        this->_f = static_cast<float>(this->_i);
        return (0);
    }
    return (1);
}

void    Conv::display() const
{
    std::cout << '\n';
    if (isprint(this->_c))
        std::cout << "char: " << this->_c << std::endl;
    else if (this->_ret == 1)
        std::cout << "char: " << "Impossible" << std::endl;
    else
        std::cout << "char: " << "Non displayable" << std::endl;
    if (this->_ret == 1)
        std::cout << "int: " << "Impossible" << std::endl;
    else
        std::cout << "int: " << this->_i << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "float: " << this->_f << "f" << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "double: " << this->_d << std::endl;
    std::cout << '\n';
}
