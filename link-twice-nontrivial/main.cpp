#include <base.h>
#include <shared.h>

#include <iostream>

int main()
{
    std::cout << "In main, address of nonTrivial is " << &nonTrivial << std::endl;
    baseFunc();
    sharedFunc();
}
