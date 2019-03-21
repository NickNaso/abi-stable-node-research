package main

// #include <stdlib.h>
// #cgo CFLAGS: -I.
// #cgo LDFLAGS: -L. -lnode_api
// #include <node_api.h>
import "C"

//export Method
func Method(env C.napi_env, info C.napi_callback_info) C.napi_value {
	var res C.napi_value
	C.napi_create_int32(env, C.int(5), &res)
	return res
}

func main() {}
