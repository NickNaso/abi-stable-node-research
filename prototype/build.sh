#!/bin/bash
echo Cleanup previous build ...  && \
rm -rf libnode_api.a && \
rm -rf node_api.o && \
rm -rf libgoaddon.a && \
rm -rf libgoaddon.h && \
echo Start building N-API stub ...  && \
echo Build C library ...  && \
gcc -c node_api.c && \
ar -rcs libnode_api.a node_api.o && \
ranlib libnode_api.a && \
echo N-API stub successfully builded. && \
echo Build Go library ...  && \
go build -a -x -o libgoaddon.a -buildmode=c-archive go-napi.go && \
echo Build Node.js native add-on ... && \
npm i && \
echo Node.js native add-on successfully created. && \
echo Starting test ... && \
node index.js && \
echo Test successfully ended.
