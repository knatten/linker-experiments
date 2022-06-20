#define EXPORTING_STUFF
#include "Base.h"

#include <iostream>

int global;

void printGlobalAddresses()
{
	std::cout << "addr of global : " << &global << "  addr of inlineGlobal : " << &inlineGlobal << std::endl;
}

void outerWrapper()
{
	printGlobalAddresses();
}
