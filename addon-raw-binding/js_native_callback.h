#ifndef SRC_JS_NATIVE_CALLBACK_H_
#define SRC_JS_NATIVE_CALLBACK_H_

#include <node_api.h>

#ifdef __cplusplus
extern "C" {
#endif

napi_value CallbackMethod(napi_env env, napi_callback_info info);

void CallToAction(void* CbData);

#ifdef __cplusplus
}
#endif


#endif
