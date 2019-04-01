#include "js_native_callback.h"
#include <iostream>
#include <functional>
#include <node_api.h>
#include <assert.h>

// _cgo_export.h is auto-generated and has Go //export funcs
#include "_cgo_export.h"

// For use in JS to C++ callback wrappers to catch any Napi::Error exceptions
// and rethrow them as JavaScript exceptions before returning from the callback.
/*template <typename Callable>
inline napi_value WrapCallback(Callable callback) {
#ifdef NAPI_CPP_EXCEPTIONS
  try {
    return callback();
  } catch (const Error& e) {
    e.ThrowAsJavaScriptException();
    return nullptr;
  }
#else // NAPI_CPP_EXCEPTIONS
  // When C++ exceptions are disabled, errors are immediately thrown as JS
  // exceptions, so there is no need to catch and rethrow them here.
  return callback();
#endif // NAPI_CPP_EXCEPTIONS
}
*/


napi_value CallbackMethod(napi_env env, napi_callback_info info) {
  napi_status status;
  napi_value res;
  status = napi_create_int32(env, 5, &res);
  assert(status == napi_ok);
  return res;
}



struct Callable {
    Callable(CallbackExecutor executor, void* data) {
      ex = executor;
      cbData = data;
    }
    napi_value operator()(napi_env env, napi_callback_info info)
    {
       ex(cbData, env, info);
    }
    CallbackExecutor ex;
    void* cbData;
};
typedef struct Callable Callable;

void* CallToAction(void* CbData) { 
    /*std::function<napi_value (napi_env, napi_callback_info)> cb = [CbData](napi_env env, napi_callback_info info) -> napi_value {
        ExecuteCallback(CbData, env, info);
    };*/
    //(napi_callback) cb;
    Callable* callable = new Callable(ExecuteCallback, CbData);
    return (void*)callable;
    
    
}

