#ifndef DEFINED_SHARED_H
#define DEFINED_SHARED_H

 __attribute__ ((visibility ("hidden")))
int local_func();
int global_func();
int using_local_func();
int using_global_func();

#endif
