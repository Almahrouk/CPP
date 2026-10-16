#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

template <typename T> 
void testEasyFind(T& container, int value)
{
    try
    {
        easyfind(container, value);
        std::cout << "Element " << value << " found!" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

int main()
{
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    testEasyFind(vec, 20);
    testEasyFind(vec, 99);

    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    testEasyFind(lst, 3);

    std::deque<int> dq;
    dq.push_back(1);   
    dq.push_front(2);
    dq.push_back(3);   
    dq.push_front(4);
    testEasyFind(dq, -3);

    return 0;
}