package main

/*
#include <stdlib.h>
static int execute(size_t size, int32_t* data) {
	int32_t count = 0;
	size_t i = size;
	while(i > 0) {
		count += data[i - 1];
		i -= 1;
    }
	return count;
}
static int executePtr(size_t size, int32_t* data) {
	int32_t count = 0;
	while(size > 0) {
		count += *data++;
		size -= 1;
    }
	return count;
}
*/
import "C"
import (
	"fmt"
	"unsafe"
)

func main() {
	slice := []int32{10, 20, 30, 40, 50}
	raw := unsafe.Pointer(&slice[0])
	fmt.Println("Length of slice is ", len(slice))
	fmt.Println("Capacity of slice is ", cap(slice))
	fmt.Println(C.execute(C.size_t(len(slice)), (*C.int32_t)(raw)))
	fmt.Println(C.executePtr(C.size_t(len(slice)), (*C.int32_t)(raw)))
}
