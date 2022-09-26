#include "Data.hpp"

uintptr_t serialize(Data* ptr)
{
    return(reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
    return(reinterpret_cast<Data *>(raw));
}

int main()
{
    Data        instance(42, 'C');
    Data        *ptr;
    uintptr_t   raw;

    raw = 0;
    std::cout << "Raw : " << raw << std::endl;
    std::cout << "Instance addr: " << &instance << std::endl;
    std::cout << "instance _i = "<< instance.getI() << std::endl;
    std::cout << "instance _c = "<< instance.getC() << std::endl;
    raw = serialize(&instance);
    std::cout << "serialize(&instance) = " << raw << std::endl;
    ptr = deserialize(raw);
    std::cout << "deserialize(raw) = " << ptr << std::endl;

    std::cout << "ptr _i = "<< ptr->getI() << std::endl;
    std::cout << "ptr _c = "<< ptr->getC() << std::endl;

    return (0);
}