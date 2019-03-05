#include "js_native_callback.h"

// _cgo_export.h is auto-generated and has Go //export funcs
#include "_cgo_export.h"

/*napi_value CallbackMethod(napi_env env, napi_callback_info info) {
    napi_status status;
    napi_value res;
    status = napi_create_int32(env, 5, &res);
    assert(status == napi_ok);
    return res;
}*/

void CallToAction(void* fn) {
    ExecuteCallback(fn);
}

