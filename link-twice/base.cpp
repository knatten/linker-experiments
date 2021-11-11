#include <base.h>

#include <iostream>

/* int globalInt = 1; */

int getGlobal()
{
    std::cout << "In base, address of globalInt is " << &globalInt << std::endl;
	return globalInt;
}
