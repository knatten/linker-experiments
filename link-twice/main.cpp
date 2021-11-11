#include <base.h>
#include <shared.h>

#include <iostream>

int main()
{
    std::cout << "In main, address of globalInt is " << &globalInt << std::endl;
	return globalInt * 100 + getGlobal() + compute();
}
