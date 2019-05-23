# N-API

N-API is an API for building Node.js native Addons. It is independent from the underlying JavaScript runtime (ex V8) and is 
maintained as part of Node.js itself. This API will be Application Binary Interface (ABI) stable across versions of Node.js. 
It is intended to insulate Addons from changes in the underlying JavaScript engine and allow modules compiled for one major 
version to run on later major versions of Node.js without recompilation. 

APIs exposed by N-API are generally used to create and manipulate JavaScript values. Concepts and operations generally map 
to ideas specified in the ECMA262 Language Specification. The APIs have the following properties:

- All N-API calls return a status code of type `napi_status`. This status indicates whether the API call succeeded or failed.
- The API's return value is passed via an out parameter.
- All JavaScript values are abstracted behind an opaque type named `napi_value`.
- In case of an error status code, additional information can be obtained using `napi_get_last_error_info`. For more info see 
the error handling section.

The N-API is a C API that ensures ABI stability across Node.js versions and different compiler levels. 

A C++ API can be easier to use. To support using C++, the project maintains a C++ wrapper module called `node-addon-api`. 
This wrapper provides an inlineable C++ API. Binaries built with `node-addon-api` will depend on the symbols for the N-API 
C-based functions exported by Node.js. `node-addon-api` is a more efficient way to write code that calls N-API. 

Following the example of `node-addon-api` this project has the purpose to invastigate the possibility to write a wrapper over
N-API written in programming languages different from C / C++.
 
* **[ABI stability](/resources/napi/abi_stability.md)**
