#include "js_native_callback.h"

// _cgo_export.h is auto-generated and has Go //export funcs
#include "_cgo_export.h"
  
napi_value CallbackMethod(napi_env env, napi_callback_info info) {
    napi_value res;
    napi_create_int32(env, 5, &res);
    return res;
}
