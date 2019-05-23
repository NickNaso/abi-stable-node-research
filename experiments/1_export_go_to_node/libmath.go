package main

import "C"

//export Add
func Add(a, b C.double) C.double {
	return a + b
}

func main() {}
