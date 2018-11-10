package main

/*
#cgo LDFLAGS: -L. -lsum
#cgo CFLAGS: -I.
extern double sum(double a, double b);
*/
import "C"

//export Add
func Add(a, b C.double) C.double {
	return C.sum(a, b)
}

func main() {}
