#pragma once
extern int global;

inline int inlineGlobal;
//__declspec(dllexport) inline int inlineGlobal;

//void printGlobalAddresses();
#ifdef EXPORTING_STUFF
__declspec(dllexport)
#else
__declspec(dllimport)
#endif
void printGlobalAddresses();

void outerWrapper();
//__declspec(dllexport) void outerWrapper();
