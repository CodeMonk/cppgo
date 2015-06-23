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
	goHandle := uint64(handle)

	gotos := C.goToString(C.uint64_t(goHandle))
	result := C.GoString(gotos)

	fmt.Println("Vars:")
	fmt.Printf("    handle: %#v (%T)\n", handle, handle)
	fmt.Printf("  goHandle: %#v (%T)\n", goHandle, goHandle)
	fmt.Printf("     gotos: %#v (%T)\n", gotos, gotos)

	fmt.Printf("Result:\n    %s\n", result)

	C.goFree(handle)

}
