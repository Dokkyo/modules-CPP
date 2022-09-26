#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <iostream>
#include <stack>
#include <iterator>
#include <list>

template<typename T>
class MutantStack : public std::stack<T>
{
    public:

        MutantStack(){
            std::cout << "Mutant Constructor Called" << std::endl;
            return;};
        MutantStack(MutantStack<T> & src){
            *this = src;
        };
        ~MutantStack(){
            std::cout << "Mutant Destructor Called" << std::endl;
            return;};
        MutantStack &operator=(MutantStack<T> &rhs){
            this->c = rhs.c;
            return (*this);
        };
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;

        iterator        begin(){
            return (this->c.begin());
        };
        const_iterator  begin() const{
            return (this->c.begin());
        };
        iterator        end(){
            return (this->c.end());
        };
        const_iterator  end() const{
            return (this->c.end());
        };
};

#endif