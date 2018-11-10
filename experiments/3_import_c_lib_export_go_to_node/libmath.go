package main

/*
#cgo LDFLAGS: -L. -lsum
#cgo CFLAGS: -I.
#include <sum.h>
*/
import "C"

//export Add
func Add(a, b C.double) C.double {
	return C.sum(a, b)
}

func main() {}
