#ifndef DOG_HPP
 #define DOG_HPP

#include "classes.hpp"

class Dog : public Animal
{
    
    protected:
        
        std::string _type;

    public:
        
        Dog();
        Dog(Dog & src);
        Dog& operator=(Dog & rhs);
        virtual ~Dog();

        virtual void    makeSound() const;
        virtual std::string     getType() const;
};

 #endif