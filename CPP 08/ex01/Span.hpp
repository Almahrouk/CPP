#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>

template <typename T> 
void easyfind(T& container, int value)
{
    typename T::iterator it = find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("Not Found");
}

template <typename T> 
class Span
{
    private:
        unsigned int N;

    public:
        Span();
        Span(unsigned int N);
        Span(const Span &src);
        Span &operator=(const Span &src);
        ~Span();

        void addNumber(); // use push_back() | if number of elements is >= N -> exception
        
        // If there are no numbers stored, or only one, no span can be found. Thus, throw an exception
        shortestSpan();
        longestSpan();

};


#endif