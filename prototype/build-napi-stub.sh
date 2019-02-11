#!/bin/bash
echo Cleanup previous build ...  && \
rm -rf libnode_api.a && \
rm -rf node_api.o && \
echo Start building N-API stub ...  && \
echo Build C library ...  && \
gcc -c node_api.c && \
ar -rcs libnode_api.a node_api.o && \
ranlib libnode_api.a && \
echo N-API stub successfully builded.