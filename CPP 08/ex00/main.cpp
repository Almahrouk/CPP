#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    try
    {
        std::cout << "Searching for 20 in vector:" << std::endl;
        easyfind(vec, 20);
        std::cout << "Element found!" << std::endl;

        std::cout << "Searching for 99 in vector:" << std::endl;
        easyfind(vec, 99);
        std::cout << "Element found!" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);

    try
    {
        std::cout << "Searching for 3 in list:" << std::endl;
        easyfind(lst, 3);
        std::cout << "Element found!" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}