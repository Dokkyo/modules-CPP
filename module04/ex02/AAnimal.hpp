#ifndef AANIMAL_HPP
 #define AANIMAL_HPP

#include "classes.hpp"

class AAnimal
{
    
    protected:
        
        std::string _type;

    public:
        
        AAnimal();
        AAnimal(AAnimal & src);
        AAnimal& operator=(AAnimal & rhs);
        virtual ~AAnimal();

        virtual void            makeSound() const = 0;
        virtual std::string     getType() const;
};

 #endif