#ifdef __cplusplus 
extern "C" {
#endif
    #ifndef SRC_NODE_API_H_
    #define SRC_NODE_API_H_
    #ifdef BUILDING_NODE_EXTENSION
    #ifdef _WIN32
        // Building native module against node
        #define NAPI_EXTERN __declspec(dllimport)
    #endif
    #endif
    #include "js_native_api.h"
    #include "node_api_types.h"

    #ifdef _WIN32
    # define NAPI_MODULE_EXPORT __declspec(dllexport)
    #else
    # define NAPI_MODULE_EXPORT __attribute__((visibility("default")))
    #endif

    #ifdef __GNUC__
    #define NAPI_NO_RETURN __attribute__((noreturn))
    #else
    #define NAPI_NO_RETURN
    #endif

    struct uv_loop_s;  // Forward declaration.

    typedef napi_value (*napi_addon_register_func)(napi_env env, napi_value exports);

    typedef struct {
        int nm_version;
        unsigned int nm_flags;
        const char* nm_filename;
        napi_addon_register_func nm_register_func;
        const char* nm_modname;
        void* nm_priv;
        void* reserved[4];
    } napi_module;

    #define NAPI_MODULE_VERSION  1

    #if defined(_MSC_VER)
    #pragma section(".CRT$XCU", read)
    #define NAPI_C_CTOR(fn)                                                     \
      static void __cdecl fn(void);                                             \
      __declspec(dllexport, allocate(".CRT$XCU")) void(__cdecl * fn##_)(void) = \
          fn;                                                                   \
    static void __cdecl fn(void)
    #else
    #define NAPI_C_CTOR(fn)                              \
      static void fn(void) __attribute__((constructor)); \
    static void fn(void)
    #endif

    extern void napi_module_register(napi_module* mod);

    extern NAPI_NO_RETURN void napi_fatal_error(const char* location, size_t location_len, const char* message, size_t message_len);

    // Methods for custom handling of async operations
    extern napi_status napi_async_init(napi_env env, napi_value async_resource, napi_value async_resource_name, napi_async_context* result);

    extern napi_status napi_async_destroy(napi_env env, napi_async_context async_context);
    extern napi_status napi_make_callback(napi_env env, napi_async_context async_context, napi_value recv, napi_value func, size_t argc, const napi_value* argv, napi_value* result);

    // Methods to provide node::Buffer functionality with napi types
    extern napi_status napi_create_buffer(napi_env env, size_t length, void** data, napi_value* result);
    extern napi_status napi_create_external_buffer(napi_env env, size_t length, void* data, napi_finalize finalize_cb, void* finalize_hint, napi_value* result);
    extern napi_status napi_create_buffer_copy(napi_env env, size_t length, const void* data, void** result_data, napi_value* result);
    extern napi_status napi_is_buffer(napi_env env, napi_value value, bool* result);
    extern napi_status napi_get_buffer_info(napi_env env, napi_value value, void** data, size_t* length);

    // Methods to manage simple async operations
    extern napi_status napi_create_async_work(napi_env env, napi_value async_resource, napi_value async_resource_name, napi_async_execute_callback execute, napi_async_complete_callback complete, void* data, napi_async_work* result);
    extern napi_status napi_delete_async_work(napi_env env, napi_async_work work);
    extern napi_status napi_queue_async_work(napi_env env, napi_async_work work);
    extern napi_status napi_cancel_async_work(napi_env env, napi_async_work work);

    // version management
    extern
    napi_status napi_get_node_version(napi_env env, const napi_node_version** version);

    #if NAPI_VERSION >= 2

    // Return the current libuv event loop for a given environment
    extern napi_status napi_get_uv_event_loop(napi_env env, struct uv_loop_s** loop);

    #endif  // NAPI_VERSION >= 2

    #if NAPI_VERSION >= 3

    extern napi_status napi_fatal_exception(napi_env env, napi_value err);
    extern napi_status napi_add_env_cleanup_hook(napi_env env, void (*fun)(void* arg), void* arg);
    extern napi_status napi_remove_env_cleanup_hook(napi_env env, void (*fun)(void* arg), void* arg);
    extern napi_status napi_open_callback_scope(napi_env env, napi_value resource_object, napi_async_context context, napi_callback_scope* result);
    extern napi_status napi_close_callback_scope(napi_env env, napi_callback_scope scope);

    #endif  // NAPI_VERSION >= 3

    #ifdef NAPI_EXPERIMENTAL

    // Calling into JS from other threads
    extern napi_status napi_create_threadsafe_function(napi_env env, napi_value func, napi_value async_resource, napi_value async_resource_name, size_t max_queue_size, size_t initial_thread_count, void* thread_finalize_data, napi_finalize thread_finalize_cb, void* context, napi_threadsafe_function_call_js call_js_cb, napi_threadsafe_function* result);
    extern napi_status napi_get_threadsafe_function_context(napi_threadsafe_function func, void** result);
    extern napi_status napi_call_threadsafe_function(napi_threadsafe_function func, void* data, napi_threadsafe_function_call_mode is_blocking);
    extern napi_status napi_acquire_threadsafe_function(napi_threadsafe_function func);
    extern napi_status napi_release_threadsafe_function(napi_threadsafe_function func, napi_threadsafe_function_release_mode mode);
    extern napi_status napi_unref_threadsafe_function(napi_env env, napi_threadsafe_function func);
    extern napi_status napi_ref_threadsafe_function(napi_env env, napi_threadsafe_function func);

    #endif  // NAPI_EXPERIMENTAL

    #endif // SRC_NODE_API_H_
#ifdef __cplusplus 
}
#endif