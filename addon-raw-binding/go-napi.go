package main

// #include <stdlib.h>
// #cgo CFLAGS: -I.
// #cgo LDFLAGS: -L. -lnode_api
// #include <node_api.h>
/*
extern napi_callback go_callback_int(void*);
static inline napi_callback CallMyFunction(void* pfoo) {
    return go_callback_int(pfoo);
}
*/
import (
	"C"
)
import (
	"unsafe"
)

//export go_callback_int
func go_callback_int(pfoo unsafe.Pointer) C.napi_callback {
	foo := (*Test)(pfoo)
	return foo.cb

}

type Test struct {
}

func (s *Test) cb(env C.napi_env, info C.napi_callback_info) {
	//Method
}

func Method(env C.napi_env, info C.napi_callback_info) C.napi_value {
	var res C.napi_value
	C.napi_create_int32(env, C.int(5), &res)
	return res
}

/* //export Sbubba
func Sbubba(c NapiCallback) C.napi_callback {
	return unsafe.Pointer(c)
}*/

//export Initialize
func Initialize(env C.napi_env, exports C.napi_value) C.napi_value {
	name := C.CString("createInt32")
	defer C.free(unsafe.Pointer(name))
	data := &Test{}
	C.CallMyFunction(unsafe.Pointer(&data))
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
