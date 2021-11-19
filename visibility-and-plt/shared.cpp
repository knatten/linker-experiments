#include <shared.h>

#include <iostream>

int local_func()
{
    return 1;
}

int global_func()
{
	return 2;
}

int using_local_func()
{
    return local_func();
}

int using_global_func()
{
    return global_func();
}
