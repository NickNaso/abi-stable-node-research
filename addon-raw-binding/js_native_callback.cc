#include "js_native_callback.h"
#include <iostream>

// _cgo_export.h is auto-generated and has Go //export funcs
#include "_cgo_export.h"


auto make_function(int& x) {
  return [&]{ std::cout << x << '\n'; };
}
  
napi_value CallbackMethod(napi_env env, napi_callback_info info) {
    ExecuteCallback()
}



void CallToAction(void* CbData) { 
    
}

