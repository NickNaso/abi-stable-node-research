package main

// #include <stdlib.h>
// #cgo CXXFLAGS: -std=c++14 -stdlib=libc++
// #cgo CFLAGS: -I.
// #cgo LDFLAGS: -L. -lnode_api
// #include <node_api.h>
// #include "js_native_callback.h"
import (
	"C"
)
import (
	"unsafe"
)

type Caller struct{}

/*func (s *Caller) cb() {
	fmt.Println("Callback executed")
}*/

func (s *Caller) cb(env C.napi_env, info C.napi_callback_info) C.napi_value {
	var res C.napi_value
	C.napi_create_int32(env, C.int(5), &res)
	return res
}

//export ExecuteCallback
func ExecuteCallback(data unsafe.Pointer, env C.napi_env, info C.napi_callback_info) C.napi_value {
	caller := (*Caller)(data)
	return caller.cb(env, info)
}

/*func Method(env C.napi_env, info C.napi_callback_info) C.napi_value {
	var res C.napi_value
	C.napi_create_int32(env, C.int(5), &res)
	return res
}*/

//export Initialize
func Initialize(env C.napi_env, exports C.napi_value) C.napi_value {
	name := C.CString("createInt32")
	defer C.free(unsafe.Pointer(name))
	caller := &Caller{}
	C.CallToAction(unsafe.Pointer(&caller))
	desc := C.napi_property_descriptor{
		utf8name:   name,
		name:       nil,
		method:     (C.napi_callback)(C.CallbackMethod), //nil,
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
