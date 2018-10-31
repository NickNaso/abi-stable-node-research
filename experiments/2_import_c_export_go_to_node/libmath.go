package main

/*
#include "sum.c"
*/
import "C"

//export Add
func Add(a, b C.double) C.double {
	return C.sum(a, b)
}

func main() {}
