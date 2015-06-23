package main

// #cgo LDFLAGS: -Lcpp -ltc -lstdc++
// #cgo CFLAGS: -Icpp
// #include <cbind.h>
import "C"

import (
	"fmt"
)

func main() {
	// Connect to our c-go library, and see if we can hold the pointers.
	handle := C.goAlloc(C.CString("Go String %d"), C.int(5))

	gotos := C.goToString(handle)

	result := C.GoString(gotos)

	fmt.Printf("Result: %s\n", result)

	C.goFree(handle)

}
