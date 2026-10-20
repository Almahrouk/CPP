#include "RPN.hpp"

RPN::RPN() : _input(""), _data() {}

RPN::RPN(const std::string &input)
    : _input(input), _data() {}

RPN::RPN(const RPN &obj)
    : _input(obj._input), _data(obj._data) {}

RPN &RPN::operator=(const RPN &obj)
{
    if (this != &obj)
    {
        _input = obj._input;
        _data = obj._data;
    }
    return *this;
}

RPN::~RPN() {}

bool RPN::isValidNumber(const std::string &input, int i) const
{
    return (input[i] >=  '0' && input[i] <=  '9');
}

bool RPN::isValidOperator(const std::string &input, int i) const
{
    return (input[i] ==  '+' || input[i] ==  '-' || input[i] ==  '*' || input[i] ==  '/');
}

bool RPN::isValidInput(const std::string &input, int i) const
{
    return (isValidNumber(input, i) || isValidOperator(input, i));
}

const std::string &RPN::getInput() const
{
    return _input;
}

const std::stack<int> &RPN::getStack() const
{
    return _data;
}

void RPN::setInput(const std::string &input)
{
    _input = input;
}

void RPN::setStack(const std::stack<int> &data)
{
    _data = data;
}

int RPN::parsingInputToStack(const std::string &input, std::stack<int> &data) const
{
    std::istringstream iss(input);
    std::string token;

    while (iss >> token)
    {
        // each token must be exactly one char: a digit 0-9 or an operator
        if (token.size() != 1 || !isValidInput(token, 0))
            return InvalidInput;

        if (isValidNumber(token, 0))
            data.push(token[0] - '0');
        else
        {
            if (data.size() < 2)
                return ExpectedNumber;
            int result = 0;
            int status = calculation(token[0], data, result);
            if (status != SUCCESS)
                return status;
            data.push(result);
        }
    }
    if (data.size() != 1)
        return InvalidExpression;
    return SUCCESS;
}

int RPN::calculation(char op, std::stack<int> &data, int &result) const
{
    int right = data.top();
    data.pop();
    int left = data.top();
    data.pop();

    switch (op)
    {
    case '+': 
        result = left + right; 
        break;
    case '-': 
        result = left - right; 
        break;
    case '*': 
        result = left * right; 
        break;
    case '/':
        if (right == 0)
            return DivisionByZero;
        result = left / right;
        break;
    default:
        return InvalidInput;
    }
    return SUCCESS;
}

int RPN::run(const std::string &input)
{
    _input = input;
    _data = std::stack<int>();

    if (parsingInputToStack(_input, _data) != SUCCESS)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    std::cout << _data.top() << std::endl;
    return 0;
}

std::ostream &operator<<(std::ostream &os, const RPN &rpn)
{
    os << rpn.getInput();
    return os;
}