#ifndef CURE_HPP
 #define CURE_HPP

#include "classes.hpp"

class Cure : public AMateria
{
    private:

        std::string     _type;

    public:

        Cure();
        Cure(std::string const & type);
        Cure(Cure & src);
        Cure& operator=(Cure & rhs);
        ~Cure();

        virtual Ice* clone() const;
};


#endif