#include "RPN.hpp"

RPN::RPN(std::string str) : _rpn(str), _nb_operands(0), _nb_operators(0)
{
    // std::cout << "RPN Constructor Called\n";
}

RPN::RPN(const RPN & rhs)
{
    // std::cout << "RPN Copy Constructor Called\n";
    *this = rhs;
}

RPN & RPN::operator=(const RPN & rhs)
{
    // std::cout << "RPN Assignment operator Called\n";

    return *this;
}

RPN::~RPN()
{
    // std::cout << "RPN Destructor Called\n";
}

int    RPN::evaluateRPN()
{
    for (char c : this->_rpn) 
    {
        if (isdigit(c)){
        {
            _nb_operands++;
            this->_stk.push(c - '0');
        }
        } else if (isspace(c)){
            ;
        }
        else if(c == '+' || c == '-' || c == '*' || c == '/'){
            _nb_operators++;
            if (_nb_operators >= _nb_operands)
            {
                std::cout << "Error\n";
                return -1;
            }
            long op2 = this->_stk.top(); this->_stk.pop();
            long op1 = this->_stk.top(); this->_stk.pop();
            switch (c) {
                case '+': this->_stk.push(op1 + op2); break;
                case '-': this->_stk.push(op1 - op2); break;
                case '/': if (op2 == 0) throw std::runtime_error("Math error: Attempted to divide by Zero\n"); else this->_stk.push(op1 / op2); break;
                case '*': this->_stk.push(op1 * op2); break;
            }
        }
        else {
                std::cout << "Error\n";
                return -1;
            }
    }

    std::cout << "Result: " << this->_stk.top() << std::endl;
    
    return (0);
}