#ifndef _CBIND_H_
#define _CBIND_H_
#include <stdint.h>

// C bindings
//
#ifdef __cplusplus
extern "C" {
#endif

uint64_t goAlloc(char *fmt, int num);
char *goToString(uint64_t encPtr);
void goFree(uint64_t handle);

#ifdef __cplusplus
}
#endif
#endif // _CBIND_H_
