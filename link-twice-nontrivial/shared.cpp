#include <base.h>
#include <shared.h>

#include <iostream>

void sharedFunc()
{
    std::cout << "In shared, address of nonTrivial is " << &nonTrivial << std::endl;
    baseFunc();
}	
