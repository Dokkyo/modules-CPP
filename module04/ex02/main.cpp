#include "classes.hpp"

int main()
{
    //const AAnimal* meta = new AAnimal();
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    const WrongAnimal* k = new WrongCat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << k->getType() << " " << std::endl;
    k->makeSound();
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    //meta->makeSound();

    delete  k;
    delete  i;
    delete  j;
    //delete  meta;

    return 0;
}