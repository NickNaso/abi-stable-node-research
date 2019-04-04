package main

// #include <stdlib.h>
// #cgo CFLAGS: -I.
// #cgo LDFLAGS: -L. -lnode_api
// #include <node_api.h>
/*

static napi_value ooooooooo(napi_env env, napi_callback_info info) {
  napi_value res;
  napi_create_int32(env, 5, &res);
  return res;
}
*/
import "C"

//export Method
func Method(env C.napi_env, info C.napi_callback_info) C.napi_value {
	var res C.napi_value
	C.napi_create_int32(env, C.int(5), &res)
	return res
}

//export Initialize
func Initialize(env C.napi_env, exportss C.napi_value) C.napi_value {
	// napi_property_descriptor desc = { "createInt32", 0, Method, 0, 0, 0, napi_default, 0 };
	// status = napi_define_properties(env, exports, 1, &desc);
	// return exports;
}

func main() {}
