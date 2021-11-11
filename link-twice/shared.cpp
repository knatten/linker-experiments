#include <base.h>
#include <shared.h>

#include <iostream>

int compute()
{
    std::cout << "In shared, address of globalInt is " << &globalInt << std::endl;
	return getGlobal() * 10;
}	
