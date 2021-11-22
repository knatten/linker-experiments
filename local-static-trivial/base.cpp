#include <base.h>

#include <iostream>

int globby = 3;
int getStatic()
{
    static int staticInt = 2;
    std::cout << "In base, address of getStatic is " << (void*)getStatic << "\n";
    std::cout << "In base, address of staticInt is " << &globby << "\n";
	return staticInt;
}
