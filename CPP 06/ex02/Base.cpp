#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
    int n = rand() % 3;
    // std::cout << "Generated type: " << n << std::endl;
    switch (n)
    {
        case A_TYPE:
            return new A();
        case B_TYPE:
            return new B();
        case C_TYPE:
            return new C();
        default:
            return NULL;
    }
}

void identify(Base* p)
{
    std::cout << "Pointer type: " << typeid(*p).name() << std::endl;
}

void identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
    }
    catch (std::exception &e)
    {
        try
        {
            B& b = dynamic_cast<B&>(p);
            (void)b;
            std::cout << "B" << std::endl;
            // std::cout << "Exception: " << e.what() << std::endl;
        }
        catch (std::bad_cast &e)
        {
            std::cout << "C" << std::endl;
            // std::cout << "Exception: " << e.what() << std::endl;
        }
    }
    // catch (std::bad_cast &e)
    // {
    //     try
    //     {
    //         B& b = dynamic_cast<B&>(p);
    //         (void)b;
    //         std::cout << "B" << std::endl;
    //     }
    //     catch (std::bad_cast &e)
    //     {
    //         std::cout << "C" << std::endl;
    //     }
    // }
}

Base::~Base()
{
    
}