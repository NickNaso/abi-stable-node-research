package main
// #cgo CFLAGS: -I.
// #cgo LDFLAGS: -L. -lbridge
// #include "bridge.h"
import "C"

//export Add
func Add(env C.napi_env, value C.uint32_t ) {
	
	return C.exec_napi_create_int32(env, int(10))
	
}

func main() {}
