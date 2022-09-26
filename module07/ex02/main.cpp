#include "Array.tpp"

#define MAX_VAL 5

int main(int, char**)
{
    try
    {
        Array<int> numbers(MAX_VAL);
        srand(time(NULL));
        for (int i = 0; i < MAX_VAL; i++)
        {
            const int value = rand();
            numbers[i] = value;
        }
        Array<int> tmp = numbers;
        for (int i = 0; i < MAX_VAL; i++)
        {
            std::cout << std::endl;
            std::cout << "numbers : " << numbers[i] << std::endl;
            std::cout << "tmp : " << tmp[i] << std::endl;
            std::cout << std::endl;
            std::cout << "addr numbers : " << &numbers[i] << std::endl;
            std::cout << "addr tmp : " << &tmp[i] << std::endl;
            std::cout << std::endl;
        }
        for (int i = 0; i < MAX_VAL; i++)
        {
            const int value = rand();
            tmp[i] = value;
        }
        std::cout << "-----------------------" << std::endl;
        for (int i = 0; i < MAX_VAL; i++)
        {
            std::cout << std::endl;
            std::cout << "numbers : " << numbers[i] << std::endl;
            std::cout << "tmp : " << tmp[i] << std::endl;
            std::cout << std::endl;
            std::cout << "addr numbers : " << &numbers[i] << std::endl;
            std::cout << "addr tmp : " << &tmp[i] << std::endl;
            std::cout << std::endl;
        }
        numbers[-2] = 0;
    }
    catch (const Array<int>::InvalidIndexException &e )
    {
        std::cerr << e.what() << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
