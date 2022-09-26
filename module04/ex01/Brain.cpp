#include "classes.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(Brain & src)
{
    std::cout << "Brain Copy constructor called" << std::endl;
    *this = src;
}

Brain& Brain::operator=(Brain & rhs)
{
    int i = -1;

    while (++i < 100)
        this->ideas[i] = rhs.ideas[i];

    return(*this);
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

void    Brain::setIdea(int i, std::string const str)
{
    if (i >= 0 && i < 100)
        this->ideas[i] = str;
}

std::string &     Brain::getIdea(int i)
{
    if (i >= 0 && i < 100)
    {
        if (!this->ideas[i].empty())
            return (this->ideas[i]);
        std::cerr << ("No idea here, try another index") << std::endl;
        return (this->ideas[i]);
    }

    std::cerr << "Wrong index" << std::endl;
    return (this->ideas[0]);
}
