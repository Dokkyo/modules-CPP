#include "iter.tpp"

int main( void ) 
{
    float tab[10];
    int i = -1;

    while (++i < 10)
        tab[i] = i + 1;
    i = -1;
    while (++i < 10)
        std::cout << std::fixed << std::setprecision(1) << "Tab element " << i << ": " << tab[i] << std::endl;
    std::cout << std::endl;
    ::iter(tab, 10.0f, ::add);
    
    std::cout << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << std::endl;
    int tab2[10];
    i = -1;
    while (++i < 10)
        tab2[i] = i + 10;
    i = -1;
    while (++i < 10)
        std::cout << std::fixed << std::setprecision(1) << "Tab element " << i << ": " << tab2[i] << std::endl;
    std::cout << std::endl;
    ::iter(tab2, 10, ::add);

    return 0;
}

// class Awesome
// {
// public:
// Awesome( void ) : _n( 42 ) { return; }
// int get( void ) const { return this->_n; }
// private:
// int _n;
// };
// std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }
// template< typename T >
// void print( T const & x ) { std::cout << x << std::endl; return; }

// int main() 
// {
//     int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
//     Awesome tab2[5];

//     iter( tab, 5, print );
//     //iter( tab2, 5, print );

// return 0;
// }