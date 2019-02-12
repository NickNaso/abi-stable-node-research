package main

// #cgo CFLAGS: -I.
// #cgo LDFLAGS: -L. -lsumstub
// #include <sum.h>
import "C"

//export Add
func Add(a, b C.double) C.double {
	return C.sum(a, b)
}

func main() {}
