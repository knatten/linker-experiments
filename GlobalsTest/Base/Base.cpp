#include "Base.h"

#include <iostream>

int global;

void printGlobalAddresses()
{
	std::cout << "global : " << &global << "  inlineGlobal : " << &inlineGlobal << std::endl;
}

void outerWrapper()
{
	printGlobalAddresses();
}
