#!/bin/bash

# CLEANUP PREVIOUS BUILD
echo Cleanup previous build ...  && \
rm -rf libnode_api.a && \
rm -rf node_api.o && \
rm -rf libgoaddon.a && \
rm -rf libgoaddon.h && \
rm -rf js_native_callback.o && \
rm -rf libjs_native_callback.a && \

# BUILD N-API STUB
echo Start building N-API stub ...  && \
echo Build C library ...  && \
gcc -c node_api.c && \
ar -rcs libnode_api.a node_api.o && \
ranlib libnode_api.a && \
echo N-API stub successfully builded. && \

# BUILD CALLBACK SYSTEM
#echo Start building callback handler ...  && \
#echo Build C library to handle callback ...  && \
#gcc -c js_native_callback.c -I. && \
#ar -rcs libjs_native_callback.a js_native_callback.o && \

# BUILD C ARCHIVE / STATIC LIBRARY FROM GO
echo Build Go library ...  && \
go build -a -x -o libgoaddon.a -buildmode=c-archive #&& \

# BUILD NATIVE ADD-ON
#echo Build Node.js native add-on ... && \
#npm i && \

# TEST NATIVE ADD-ON
#echo Node.js native add-on successfully created. #&& \
#echo Starting test ... && \
#node index.js && \
#echo Test successfully ended.
