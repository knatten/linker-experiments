#include <base.h>
#include <shared.h>

#include <iostream>

int main()
{
    std::cout << "In main\n";
    std::cout << "In main, address of getStatic is " << (void*)getStatic << "\n";
	return getStatic() + compute();
}
