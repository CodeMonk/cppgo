//
// Simple class to instantiate to test cgo stuffage.  Mainly pointer testing
//

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "testclass.hpp"


CGoPlayground::CGoPlayground(char *strValue, uint32_t lValue,
        uint64_t llValue)
{
    StrValue = strdup(strValue);
    LValue = lValue;
    LLValue = llValue;
}

// Dump out our instance, into a string
char *CGoPlayground::ToString(uint32_t bufLen, char *buf)
{
    size_t written;

    written = snprintf(buf, bufLen-1, "CGoPlayground <%p>\n\
    StrValue: %.40s (%ld bytes)\n\
      LValue: 0x%08x\n\
     LLValue: 0x%016lx\n\n", this, StrValue, strlen(StrValue), LValue, LLValue);
    if (written >= bufLen) {
        printf("Warning:  Truncated the write!  Wrote %ld of %d bytes!\n", written, bufLen-1);
    }

    return buf;

} // CGoPlayground::ToString


// C bindings
//
CGoPlayground * classAlloc(char *fmt, int num)
{
    char buf[1024];

    snprintf(buf, sizeof(buf)-1, fmt, num);
    uint32_t  masker = num;
    uint32_t lValue = (masker << 24) | (masker << 16) | (masker << 8) | masker;
    // Flip our bits
    masker = ~masker;
    uint64_t llValue = ((uint64_t)lValue << 32) | (masker << 24) | (masker << 16) | (masker << 8) | masker;

    CGoPlayground *ptr = new CGoPlayground(buf, lValue, llValue);

    return ptr;
}
void classFree(CGoPlayground *handle)
{
    delete handle;
}
