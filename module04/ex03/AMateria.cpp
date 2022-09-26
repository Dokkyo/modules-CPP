#include "classes.hpp"

AMateria::AMateria()
{
    std::cout << "AMateria Constructor Called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
    std::cout << "AMateria Constructor Called with type : " << type << std::endl;
}

AMateria::~AMateria()
{
    std::cout << "AMateria Destructor Called" << std::endl;
}

std::string const &     AMateria::getType() const
{
    return (this->_type);
}

void    AMateria::use(ICharacter& target)
{
    
}
