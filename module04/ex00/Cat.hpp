#ifndef CAT_HPP
 #define CAT_HPP

#include "classes.hpp"

class Cat : public Animal
{
    
    protected:

        std::string _type;

    public:
        
        Cat();
        Cat(Cat & src);
        Cat& operator=(Cat & rhs);
        virtual ~Cat();

        void    makeSound() const;
        std::string     getType() const;
};

 #endif