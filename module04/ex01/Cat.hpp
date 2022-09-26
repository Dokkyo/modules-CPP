#ifndef CAT_HPP
 #define CAT_HPP

#include "classes.hpp"

class Cat : public Animal
{
    private:

        Brain   *brain;

    protected:
        
        std::string _type;

    public:
        
        Cat();
        Cat(Cat & src);
        Cat& operator=(Cat & rhs);
        virtual ~Cat();

        virtual void            makeSound() const;
        virtual std::string     getType() const;
        virtual Brain          *getBrain() const;
};

 #endif