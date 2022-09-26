#ifndef ICE_HPP
 #define ICE_HPP

#include "classes.hpp"

class Ice : public AMateria
{
    private:
    
        std::string     _type;

    public:
    
        Ice();
        Ice(std::string const & type);
        Ice(Ice & src);
        Ice& operator=(Ice & rhs);
        ~Ice();

        virtual Ice* clone() const;
};


#endif