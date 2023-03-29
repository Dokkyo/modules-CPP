#include "RPN.hpp"

int main(int ac, char **av) {

    if (ac == 2)
    {
        try
        {
            RPN     rpn(av[1]);

            rpn.evaluateRPN();
        }
        catch(const std::runtime_error & e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    else
        std::cout << "Wrong number arguments\n";

    return 0;
}