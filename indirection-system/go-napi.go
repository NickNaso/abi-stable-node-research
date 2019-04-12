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

//export Initialize
func Initialize(env C.napi_env, exports C.napi_value) C.napi_value {
	name := C.CString("createInt32")
	desc := C.napi_property_descriptor{name, nil, (C.napi_callback)(nil), nil, nil, nil, C.napi_default, nil}
	C.napi_define_properties(env, exports, 1, &desc)
	return exports
}

func main() {}
