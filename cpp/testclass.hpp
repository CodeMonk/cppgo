//
// Simple class to instantiate to test cgo stuffage
//
#ifndef __TESTCLASS_HPP_
#define __TESTCLASS_HPP_

#include <stdlib.h>
#include <stdint.h>

class CGoPlayground {
    private:
        char *StrValue;
        uint32_t LValue;
        uint64_t LLValue;
    public:
        CGoPlayground(char *strValue, uint32_t lValue, uint64_t llValue);
        ~CGoPlayground() { free(StrValue); }
        char *getStrValue() { return StrValue; }
        uint32_t getLValue() { return LValue; }
        uint64_t getLLValue() { return LLValue; }
        char *ToString(uint32_t bufLen, char* buf);
};


CGoPlayground * classAlloc(char *fmt, int num);
void classFree(CGoPlayground *handle);
#endif // __TESTCLASS_HPP_
