#include "classes.hpp"

int main()
{
    Animal  *ani[4];
    int     i;

    for (i = 0; i < 2; ++i)
    {
        ani[i] = new Dog();
        std::cout << std::endl;
    }
    for (i = 2; i < 4; ++i)
    {
        ani[i] = new Cat();
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    for (i = 3; i >= 0; --i)
    {
        delete ani[i];
        std::cout << std::endl;
    }
    
    std::cout << std::endl;

    Cat cat;
    for (i= 0; i < 5; ++i)
    {
        cat.getBrain()->setIdea(i, "idea");
    }

    Cat cat2(cat);
    for (i= 0; i < 5; ++i)
    {
        std::cout << std::endl;
        std::cout << cat.getBrain()->getIdea(i) << std::endl;
        std::cout << cat2.getBrain()->getIdea(i) << std::endl;
        std::cout << &(cat.getBrain()->getIdea(i)) << std::endl;
        std::cout << &(cat2.getBrain()->getIdea(i)) << std::endl;
    }
    for (i= 0; i < 5; ++i)
    {
        cat2.getBrain()->setIdea(i, "aedi");
    }
    std::cout << "----------------------" << std::endl;
    for (i= 0; i < 5; ++i)
    {
        std::cout << std::endl;
        std::cout << cat.getBrain()->getIdea(i) << std::endl;
        std::cout << cat2.getBrain()->getIdea(i) << std::endl;
        std::cout << &(cat.getBrain()->getIdea(i)) << std::endl;
        std::cout << &(cat2.getBrain()->getIdea(i)) << std::endl;
    }

    return 0;
}