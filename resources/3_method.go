package main

import (
	"fmt"
	"unsafe"
)

/*
extern void go_callback_int(void*, int);
static inline void CallMyFunction(void* pfoo) {
    go_callback_int(pfoo, 5);
}
*/
import "C"

//export go_callback_int
func go_callback_int(_ unsafe.Pointer, p1 C.int) {
	MyCallbackFunc(p1)
}

func MyCallback(x C.int) {
	fmt.Println("callback with", x)
}

// we store it in a global variable so that the garbage collector
// doesn't clean up the memory for any temporary variables created.
var MyCallbackFunc = MyCallback

func main() {
	C.CallMyFunction(nil)
}
