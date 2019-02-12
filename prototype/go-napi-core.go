package main

// #cgo CFLAGS: -I.
// #cgo LDFLAGS: -L. -lnode_api
// #include <node_api.h>
import "C"

//export Method
func Method(env C.napi_env, info C.napi_callback_info) C.napi_value {
	var res C.napi_value
	C.napi_create_int32(env, 5, &res)
	return res
}

func main() {}

/*
napi_value Method(napi_env env, napi_callback_info info) {
  napi_status status;
  napi_value res;
  status = napi_create_int32(env, Add(1, 4), &res);
  assert(status == napi_ok);
  return res;
}
*/
