#include <stdio.h>
//
// Test using our Cgo playground
//

#include <stdio.h>
#include <stdint.h>
#include "testclass.hpp"
#include "cbind.h"

#define NUM_INSTANCES 5
#define STR_LEN 80

// Pointer holder
typedef struct {
    uint64_t holder[NUM_INSTANCES];
} StorageTestPointers;

StorageTestPointers gblPointers;

void simpleTest()
{
    CGoPlayground * holders[NUM_INSTANCES];
    char buf[1024];

    for (int i=0; i < NUM_INSTANCES; i++) {
        holders[i] = classAlloc((char*)"String %d", i+1);
    }

    // And, display them all
    for (int i=0; i < NUM_INSTANCES; i++) {
        printf("%s", holders[i]->ToString(sizeof(buf), buf));
    }
}

void storageTestStore()
{
    CGoPlayground *ptr;

    for (int i=0; i < NUM_INSTANCES; i++) {
        ptr  = classAlloc((char*)"Stored %d", i+1);
        gblPointers.holder[i] = (uint64_t)ptr;
    }
}

void storageTestDisplay()
{
    static char buf[1024];
    CGoPlayground *ptr;

    // And, display them all
    for (int i=0; i < NUM_INSTANCES; i++) {
        ptr = (CGoPlayground *)gblPointers.holder[i];
        printf("%s", ptr->ToString(sizeof(buf), buf));
    }
}


int main () {
    // Allocate three instances, and display them
    simpleTest();

    // Allocate some instances, and store the pointers globally in 64bit uints.
    storageTestStore();

    // Display the stored instances
    storageTestDisplay();
}
