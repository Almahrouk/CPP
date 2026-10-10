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

        void addNumber(int num); // use push_back() | if number of elements is >= N -> exception
        
        // If there are no numbers stored, or only one, no span can be found. Thus, throw an exception
        // template <class T>
        int shortestSpan();
        int longestSpan();

};


#endif