#ifndef BRAIN_HPP
 #define BRAIN_HPP

#include "classes.hpp"

class Brain
{

    private:
        
        std::string     ideas[100];

    public:

        Brain();
        Brain(Brain & src);
        Brain& operator=(Brain & rhs);
        ~Brain();

        void            setIdea(int i, std::string const str);
        std::string &   getIdea(int i);
};

#endif