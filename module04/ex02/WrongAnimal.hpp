#ifndef WRONGANIMAL_HPP
 #define WRONGANIMAL_HPP

#include "classes.hpp"

class WrongAnimal
{
    
    protected:
        
        std::string _type;

    public:
        
        WrongAnimal();
        WrongAnimal(WrongAnimal & src);
        WrongAnimal& operator=(WrongAnimal & rhs);
        virtual ~WrongAnimal();

        void    makeSound() const;
        std::string     getType() const;
};

 #endif