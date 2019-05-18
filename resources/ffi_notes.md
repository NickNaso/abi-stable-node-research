# Notes

This section contains notes that cames from my study about FFI (Foreign function interface).

## Go  

Starting from Go 1.6 cgo has new rules.

> Go code may pass a Go pointer to C provided that the Go memory to which it points does not contain any Go pointers.

See: https://github.com/golang/go/issues/12416

These rules are checked during the runtime, and if violated program crashes. At the moment it is possible to disable checks using GODEBUG=cgocheck=0 environment variable. But in future that might stop working.

So it is not possible anymore to pass a pointer to C code, if the memory to which it is pointing stores a Go function/method pointer. There are several ways to overcome this limitations, but I guess in most of them you should store a synchronized data structure which represents the correspondence between a certain id and the actual pointer. This way you can pass an id to the C code, not a pointer.

The code solving this problem might look like **[this](1_method.go)**.

For more information see: https://github.com/golang/go/wiki/cgo#function-variables


It depends exactly what you need to do with the callback function - but a trick that might work is to not pass the Go function, but a pointer to a struct with the function on it that you want.

The code solving this problem might look like **[this](2_method.go)**.

Another option might be to use a global variable as you had in your example, and then forgo passing anything useful in the pointer to C.

The code solving this problem might look like **[this](3_method.go)**.

Reference: https://stackoverflow.com/questions/37157379/passing-function-pointer-to-the-c-code-using-cgo

[Call Go functions from C](https://stackoverflow.com/questions/6125683/call-go-functions-from-c)
