#include "Span.hpp"

Span::Span() : _size(0), _idx(0)
{
    std::cout << "Default Constructor Called" << std::endl;
}

Span::Span(unsigned int N) : _size(N)
{
    std::cout << "Default Constructor Called with size " << N << std::endl;
}

Span::~Span()
{
    std::cout << "Default Destructor Called" << std::endl;
}

void    Span::addNumber(int nbr)
{
    if (this->_a.size() < this->_size)
    {
        this->_a.push_back(nbr);
        ++this->_idx;
    }
    else
        throw Span::MaxReachedException();
}

int     Span::Abs(int nb)
{
    if (nb < 0)
        return (-nb);
    return (nb);
}

int     Span::shortestSpan()
{
    if (this->_a.size() > 1)
    {
        std::vector<int> temp;

        temp = this->_a;
        std::sort(temp.begin(), temp.end());
        this->_res = temp[1] - temp[0];
        for(unsigned int i = 0; i < this->_size - 1; ++i)
        {
            if (this->_res > temp[i + 1] - temp[i])
                this->_res = temp[i + 1] - temp[i];
        }
        return (this->_res);
    }
    else
        throw Span::SizeException();
}

int     Span::longestSpan()
{
    if (this->_a.size() > 1)
    {
        std::vector<int> temp;

        temp = this->_a;
        sort(temp.begin(), temp.end());
        return(temp[temp.size() - 1] - temp[0]);
    }
    else
        throw Span::SizeException();
}

void    Span::iterator(unsigned int N)
{
    if (N > this->_size)
        throw Span::SizeException();
    else
    {
        for(unsigned int i = 0; i < N; ++i)
        {
            if (this->_idx == this->_size)
                throw Span::MaxReachedException();
            else
                this->addNumber(i);
        }
    }
}