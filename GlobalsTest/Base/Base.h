#pragma once
extern int global;

//inline int inlineGlobal;
__declspec(dllexport) inline int inlineGlobal;

//void printGlobalAddresses();
__declspec(dllexport) void printGlobalAddresses();

void outerWrapper();
//__declspec(dllexport) void outerWrapper();
