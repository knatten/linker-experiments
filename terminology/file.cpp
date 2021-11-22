extern int global1; // No symbol, static storage duration
int global2; // External linkage, global symbol, static storage duration
static int global3; // Internal linkage, local symbol, static storage duration

inline int global4 = 2;

namespace {
    int global5; //Internal linkage, local symbol, static storage duration
    
    namespace namespace1 {
        int global6; //Internal linkage, local symbol, static storage duration
    }
}

namespace namespace2 {
    int global7; //External linkage, global symbol, static storage duration
}

void function1() // External linkage, global symbol
{
    int local1; // No linkage, no symbol, automatic storage duration
    static int local2; // Internal Linkage, local symbol, static storage duration
}

namespace {
    void function2() //Internal linkage, local symbol
    {}
}

// TODO: Classes and their members, local classes (inside functions)
// TODO: Say something about language linkage maybe?
