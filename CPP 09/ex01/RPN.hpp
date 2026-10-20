#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <stack>

class RPN
{
    private:
        enum Status
        {
            SUCCESS = 0,
            InvalidInput,
            ExpectedNumber,
            InvalidExpression,
            DivisionByZero
        };

        std::string      _input;
        std::stack<int>  _data;

    public:
        RPN();
        RPN(const std::string &input);
        RPN(const RPN &obj);
        RPN &operator=(const RPN &obj);
        ~RPN();

        bool isValidNumber(const std::string &input, int i) const;
        bool isValidOperator(const std::string &input, int i) const;
        bool isValidInput(const std::string &input, int i) const;

        const std::string      &getInput() const;
        const std::stack<int>  &getStack() const;
        void setInput(const std::string &input);
        void setStack(const std::stack<int> &data);

        int parsingInputToStack(const std::string &input, std::stack<int> &data) const;
        int calculation(char op, std::stack<int> &data, int &result) const;
        int run(const std::string &input);
};

std::ostream &operator<<(std::ostream &os, const RPN &rpn);

#endif