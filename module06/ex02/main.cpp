#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <stdexcept>
#include <typeinfo>

A * a_class()
 {
    A   *a = new A;

    return(a);
}

B * b_class()
{
    B   *b = new B;

    return(b);
}

C * c_class()
{
    C   *c = new C;

    return(c);
}

Base *  generate(void)
{
    int nbr;

    srand (time(NULL));
    nbr = rand() % 3;

    if (nbr == 0)
        return (a_class());
    else if (nbr == 1)
        return (b_class());
    else if (nbr == 2)
        return (c_class());
    return NULL;
}

void identify(Base* p)
{
    A   *a;
    B   *b;
    C   *c;

    a = dynamic_cast<A *>(p);
    if (a)
    {
        std::cout << "True Type by pointer is A." << std::endl;
        return ;
    }
    b = dynamic_cast<B *>(p);
    if (b)
    {
        std::cout << "True Type by pointer is B." << std::endl;
        return ;
    }
    c = dynamic_cast<C *>(p);
    if (c)
    {
        std::cout << "True Type by pointer is C." << std::endl;
        return ;
    }
}



void identify(Base & p)
{
    try
    {
        A & a = dynamic_cast<A &>(p);
        static_cast<void>(a);
        std::cout << "True Type by ref is A." << std::endl;
        return;
    }
    catch (std::bad_cast &bc)
    {

    }
    try
    {
        B & b = dynamic_cast<B &>(p);
        static_cast<void>(b);
        std::cout << "True Type by ref is B." << std::endl;
        return;
    }
    catch (std::bad_cast &bc)
    {

    }
    try
    {
        C & c = dynamic_cast<C &>(p);
        static_cast<void>(c);
        std::cout << "True Type by ref is C." << std::endl;
        return;
    }
    catch (std::bad_cast &bc)
    {

    }
}

int main()
{
    Base    *p;

    p = generate();
    identify(p);
    identify(*p);

    delete p;
    return 0;
}