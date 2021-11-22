#include <base.h>
#include <shared.h>

#include <iostream>

int compute()
{
    std::cout << "In shared\n";
    std::cout << "In shared, address of getStatic is " << (void*)getStatic << "\n";
	return getStatic() * 10;
}	
