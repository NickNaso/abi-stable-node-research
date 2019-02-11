#include "node_api.h"

NAPI_EXTERN napi_status
napi_get_last_error_info(
    napi_env env, 
    const napi_extended_error_info** result) {
        return napi_ok;
}

// Getters for defined singletons
NAPI_EXTERN napi_status 
napi_get_undefined(
    napi_env env, 
    napi_value* result) {
        return napi_ok;
}
NAPI_EXTERN napi_status 
napi_get_null(
    napi_env env, 
    napi_value* result) {
        return napi_ok;
}
NAPI_EXTERN napi_status 
napi_get_global(
    napi_env env, 
    napi_value* result) {
        return napi_ok;
}
NAPI_EXTERN napi_status 
napi_get_boolean(
    napi_env env, 
    bool value, 
    napi_value* result) {
        return napi_ok;
}

// Methods to create Primitive types/Objects
NAPI_EXTERN napi_status 
napi_create_object(
    napi_env env, 
    napi_value* result) {
        return napi_ok;
}
NAPI_EXTERN napi_status 
napi_create_array(
    napi_env env, 
    napi_value* result) {
        return napi_ok;
}
NAPI_EXTERN napi_status 
napi_create_array_with_length(
    napi_env env, 
    size_t length, 
    napi_value* result) {
        return napi_ok;
}
NAPI_EXTERN napi_status 
napi_create_double(
    napi_env env, 
    double value, 
    napi_value* result) {
        return napi_ok;
}
NAPI_EXTERN napi_status 
napi_create_int32(
    napi_env env, 
    int32_t value, 
    napi_value* result) {
        return napi_ok;
}
NAPI_EXTERN napi_status 
napi_create_uint32(
    napi_env env, 
    uint32_t value, 
    napi_value* result) {
        return napi_ok;
}
NAPI_EXTERN napi_status 
napi_create_int64(
    napi_env env, 
    int64_t value, 
    napi_value* result) {
        return napi_ok;
}
NAPI_EXTERN napi_status 
napi_create_string_latin1(
    napi_env env, 
    const char* str, 
    size_t length, 
    napi_value* result) {
        return napi_ok;
}
NAPI_EXTERN napi_status 
napi_create_string_utf8(
    napi_env env, 
    const char* str, 
    size_t length, 
    napi_value* result) {
        return napi_ok;
}
NAPI_EXTERN napi_status 
napi_create_string_utf16(
    napi_env env, 
    const char16_t* str, 
    size_t length, 
    napi_value* result) {
        return napi_ok;
}
NAPI_EXTERN napi_status 
napi_create_symbol(napi_env env, napi_value description, napi_value* result) {

}
NAPI_EXTERN napi_status 
napi_create_function(napi_env env, const char* utf8name, size_t length, napi_callback cb, void* data, napi_value* result) {
    
}
NAPI_EXTERN napi_status 
napi_create_error(napi_env env, napi_value code, napi_value msg, napi_value* result) {

}
NAPI_EXTERN napi_status 
napi_create_type_error(napi_env env, napi_value code, napi_value msg, napi_value* result) {

}
NAPI_EXTERN napi_status 
napi_create_range_error(napi_env env, napi_value code, napi_value msg, napi_value* result) {

}

// Methods to get the native napi_value from Primitive type
NAPI_EXTERN napi_status 
napi_typeof(napi_env env, napi_value value, napi_valuetype* result) {

}
NAPI_EXTERN napi_status 
napi_get_value_double(napi_env env, napi_value value, double* result) {

}
NAPI_EXTERN napi_status 
napi_get_value_int32(napi_env env, napi_value value, int32_t* result) {

}
NAPI_EXTERN napi_status 
napi_get_value_uint32(napi_env env, napi_value value, uint32_t* result) {

}
NAPI_EXTERN napi_status 
napi_get_value_int64(
    napi_env env, 
    napi_value value, 
    int64_t* result) {

}
NAPI_EXTERN napi_status 
napi_get_value_bool(
    napi_env env,
    napi_value value, 
    bool* result) {

}

// Copies LATIN-1 encoded bytes from a string into a buffer.
NAPI_EXTERN napi_status 
napi_get_value_string_latin1(
    napi_env env, 
    napi_value value,
    char* buf, 
    size_t bufsize, 
    size_t* result) {

}