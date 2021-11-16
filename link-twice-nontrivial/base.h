#ifndef DEFINED_BASE_H
#define DEFINED_BASE_H

#include <iostream>

struct NonTrivial
{
    NonTrivial()
    {
        std::cout << "Constructed\n";
    }
};

inline NonTrivial nonTrivial;

void baseFunc();
#endif
