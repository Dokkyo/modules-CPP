#ifndef SPAN_HPP
#define SPAN_HPP

#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <algorithm>

class Span
{
    private:

        unsigned int        _size;
        unsigned int        _idx;
        std::vector<int>    _a;
        int                 _res;

    public:

        Span();
        //canonical
        Span(unsigned int N);
        ~Span();

        class MaxReachedException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Maximum Numbers were added.");
                }
        };
        class SizeException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Size problem.");
                }
        };
        void    addNumber(int nbr);
        int     Abs(int nb);
        int     shortestSpan();
        int     longestSpan();
        void    iterator(unsigned int N);
};

#endif