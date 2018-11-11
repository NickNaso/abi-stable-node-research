#include "bridge.h"

napi_status exec_napi_create_int32(napi_env env, uint32_t value, napi_value* result) {
    return napi_create_int32(env, value, result);
}