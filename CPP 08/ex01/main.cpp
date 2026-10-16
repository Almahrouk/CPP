#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    try
    {
        Span sp_empty = Span(5);
        std::cout << sp_empty.shortestSpan() << std::endl;
        std::cout << sp_empty.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Span sp_empty = Span(5);
        sp.addNumber(11);
        std::cout << sp_empty.shortestSpan() << std::endl;
        std::cout << sp_empty.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Span sp_full = Span(5);
        sp_full.addNumber(6);
        sp_full.addNumber(3);
        sp_full.addNumber(17);
        sp_full.addNumber(9);
        sp_full.addNumber(11);
        sp_full.addNumber(12);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}