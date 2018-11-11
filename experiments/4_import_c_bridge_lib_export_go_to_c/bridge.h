#include <node/node_api.h>
#ifdef __cplusplus 
extern "C" {
#endif
    #ifndef _BRIDGE_H
    #define _BRIDGE_H
        extern napi_status exec_napi_create_int32(napi_env env, uint32_t value, napi_value* result);
    #endif
#ifdef __cplusplus 
}
#endif