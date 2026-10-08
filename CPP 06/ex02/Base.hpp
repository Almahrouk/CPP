#ifndef BASE_HPP
#define BASE_HPP

#include <stdint.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <typeinfo>
#include <iostream>
#include <exception>

enum e_type
{
    A_TYPE,
    B_TYPE,
    C_TYPE
};

class A;
class B;
class C;

class Base
{
    public:
        virtual ~Base();
};
    
Base *generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
