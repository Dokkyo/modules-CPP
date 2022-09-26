#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <cstdlib>

template<typename T>
class Array
{
    private:
        
        unsigned int    _size;
        T               *_tab;
    
    public:

        Array() : _size(0), _tab(new T){
            std::cout << "Array constructor Called" << std::endl;
        }

        Array(unsigned int n) : _size(n), _tab(new T[n]){

            std::cout << "Array constructor Called with size " << n << std::endl;
        }

        Array(Array & src){
            std::cout << "Copy Constructor Called" << std::endl;
            if (this->_size > 0)
                this->_tab = new T[this->_size];
            else
                this->_tab = new T;
            *this = src;
        }

        Array & operator=(Array & rhs){
            this->_size = rhs._size;
            for(unsigned int i = 0; i < this->_size; ++i)
            {
                this->_tab[i] = rhs._tab[i];
            }
            return (*this);
        }
        ~Array(){
            delete [] this->_tab;
            std::cout << "Array Destructor Called" << std::endl;
        }

        class InvalidIndexException : public std::exception{
            public:
                virtual const char* what() const throw()
                {
                    return ("Index is incorrect.");
                }
        };

        T & operator[](int i){
            if (i < 0){
                throw InvalidIndexException();
            }
            else
                return (this->_tab[i]);
        }

        unsigned int    size() const{
            return (this->_size);
        }
};