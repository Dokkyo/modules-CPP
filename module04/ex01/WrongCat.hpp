#ifndef WRONGCAT_HPP
 #define WRONGCAT_HPP

#include "classes.hpp"

class WrongCat : public WrongAnimal
{
    
    protected:
        
        std::string _type;

    public:
        
        WrongCat();
        WrongCat(WrongCat & src);
        WrongCat& operator=(WrongCat & rhs);
        virtual ~WrongCat();

        void    makeSound() const;
        std::string     getType() const;
};

 #endif