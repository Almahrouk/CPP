#ifndef ESAYFIND_HPP
#define ESAYFIND_HPP

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

#endif