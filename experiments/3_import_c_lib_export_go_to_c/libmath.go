package main

/*

*/
import "C"

//export Add
func Add(a, b C.double) C.double {
	return a + b//C.sum(a, b)
}

func main() {}
