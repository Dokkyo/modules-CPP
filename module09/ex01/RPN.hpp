#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <vector>

class RPN
{
    public:
        RPN(std::string str);
        RPN(const RPN & rhs);
        RPN & operator=(const RPN & rhs);
        ~RPN();

        int    evaluateRPN();

    private:
        RPN();
        std::string         _rpn;
        int                 _nb_operators;
        int                 _nb_operands;
        std::stack<long>    _stk;
        std::vector<char>    _operator;
};

#endif