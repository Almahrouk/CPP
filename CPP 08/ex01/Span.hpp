#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>

class Span
{
    private:
        unsigned int N;
        std::vector<int> vec;

    public:
        Span();
        Span(unsigned int N);
        Span(const Span &src);
        Span &operator=(const Span &src);
        ~Span();

        void addNumber(int num);
        int shortestSpan();
        int longestSpan();
        
        template<typename T>
        void addRange(T begin, T end)
        {
            if (static_cast<unsigned int>(std::distance(begin, end)) > this->N - this->vec.size())
                throw std::runtime_error("Out Of Range");
            this->vec.insert(this->vec.end(), begin, end);
        }
};


#endif