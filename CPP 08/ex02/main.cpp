#include "MutantStack.hpp"
#include <iostream>

int main()
{
    // std::stack<int>::iterator it; // Error: std::stack has no iterator type
    
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << "Pop: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << "Print: " << *it << std::endl;
        ++it;
    }
    
    std::stack<int> s(mstack);
    return 0;
}