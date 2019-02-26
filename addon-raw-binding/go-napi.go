package main

// #include <stdlib.h>
// #cgo CFLAGS: -I.
// #cgo LDFLAGS: -L. -lnode_api
// #include <node_api.h>
// extern void ACFunction();
// extern napi_callback create_napi_callback();
import (
	"C"
)
import (
	"fmt"
	"unsafe"
)

//export Method
func Method(env C.napi_env, info C.napi_callback_info) C.napi_value {
	var res C.napi_value
	C.napi_create_int32(env, C.int(5), &res)
	return res
}

//export AGoFunction
func AGoFunction() {
	fmt.Println("AGoFunction()")
}

//export Initialize
func Initialize(env C.napi_env, exports C.napi_value) C.napi_value {
	name := C.CString("createInt32")
	defer C.free(unsafe.Pointer(name))

	desc := C.napi_property_descriptor{
		utf8name:   name,
		name:       nil,
		method:     nil,
		getter:     nil,
		setter:     nil,
		value:      nil,
		attributes: C.napi_default,
		data:       nil,
	}
	C.napi_define_properties(env, exports, 1, &desc)
	return exports
}

func main() {}
