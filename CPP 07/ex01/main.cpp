#include <iostream>
#include <string>
#include "iter.hpp"

// Function that modifies the element
void increment(int& n)
{
    ++n;
}

// Function that only reads the element
void printInt(const int& n)
{
    std::cout << n << " ";
}

// Function that reads a string
void printString(const std::string& str)
{
    std::cout << str << " ";
}

// Function template
template <typename T>
void print(const T& value)
{
    std::cout << value << " ";
}

int main()
{
    // Test 1: non-const array + modifying function
    int numbers[] = {1, 2, 3, 4, 5};

    std::cout << "Before increment: ";
    iter(numbers, 5, printInt);
    std::cout << std::endl;

    iter(numbers, 5, increment);

    std::cout << "After increment:  ";
    iter(numbers, 5, printInt);
    std::cout << std::endl;

    // Test 2: string array + const reference function
    std::string words[] = {"Hello", "world", "from", "iter"};

    std::cout << "Strings: ";
    iter(words, 4, printString);
    std::cout << std::endl;

    // Test 3: const array
    const int values[] = {10, 20, 30};

    std::cout << "Const array: ";
    iter(values, 3, printInt);
    std::cout << std::endl;

    // Test 4: function template as third parameter
    std::cout << "Template function: ";
    iter(numbers, 5, print<int>);
    std::cout << std::endl;

    return 0;
}
