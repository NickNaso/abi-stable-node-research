package main

/*
#cgo CFLAGS: -I.
#cgo LDFLAGS: -L. -lsum
#include "sum.h"
*/
import "C"

//export Add
func Add(a, b C.double) C.double {
	return C.sum(a, b)
}

func main() {}
