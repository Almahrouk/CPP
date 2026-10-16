#include "Span.hpp"

Span::Span()
{
	std::cout << "Span Default constructor called" << std::endl;
    this->N = 0;
}

Span::Span(unsigned int N)
{
	// std::cout << "Span Parameter constructor called" << std::endl;
    this->N = N;
}

Span::Span(const Span &src)
{
	// std::cout << "Span Copy constructor called" << std::endl;
    if (this != &src)
    {
        *this = src;
    }
}

Span &Span::operator=(const Span &src)
{
	// std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
    {
        this->N = src.N;
        this->vec = src.vec;
    }
    return *this;
}

Span::~Span()
{
	// std::cout << "Span Destructor called" << std::endl;
}

void Span::addNumber(int num) 
{
    if (this->vec.size() >= N)
        throw std::runtime_error("Out Of Range");
    this->vec.push_back(num);
}

int Span::shortestSpan()
{
    if (this->vec.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span");
    std::sort(this->vec.begin(), this->vec.end());
    int shortest = this->vec[1] - this->vec[0];
    for(std::vector<int>::iterator it = this->vec.begin(); it != this->vec.end() - 1; it++)
    {
        int temp = *(it + 1) - *it;
        if (temp < shortest)
            shortest = temp;
    }
    return shortest;
}

int Span::longestSpan()
{
    if (this->vec.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span");
    std::sort(this->vec.begin(), this->vec.end());
    int longest = this->vec.back() - this->vec.front();
    return longest;
}
