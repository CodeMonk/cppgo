#include "testclass.hpp"
#include "cbind.h"


uint64_t goAlloc(char *fmt, int num)
{
    return (uint64_t)classAlloc(fmt, num);
}

char *goToString(uint64_t encPtr)
{
    CGoPlayground *ptr = (CGoPlayground *)encPtr;
    static char buf[1024];

    ptr->ToString(sizeof(buf), buf);
    return buf;
}

void goFree(uint64_t handle)
{
    classFree((CGoPlayground *)handle);
}
