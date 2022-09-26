#ifndef ANIMAL_HPP
 #define ANIMAL_HPP

#include "classes.hpp"

class Animal
{
    
    protected:
        
        std::string _type;

    public:
        
        Animal();
        Animal(Animal & src);
        Animal& operator=(Animal & rhs);
        virtual ~Animal();

        virtual void    makeSound() const;
        virtual std::string     getType() const;
};

 #endif