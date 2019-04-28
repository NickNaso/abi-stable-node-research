#!/bin/bash          
echo Starting build process ...  && \
echo Build C library ...  && \
export MACOSX_DEPLOYMENT_TARGET=10.7 && \
gcc -c sum.c && \
ar -rcs libsum.a sum.o && \
ranlib libsum.a && \
gcc -c sum-stub.c && \
ar -rcs libsumstub.a sum-stub.o && \
ranlib libsumstub.a && \
echo Build Go library ...  && \
go build -a -x -o libmath.a -buildmode=c-archive libmath.go && \
#ranlib libmath.a && \
#echo Compile C program && \
#gcc -c main.c && \
#gcc -o fattone main.o -L. -lsum -lmath
#echo Build Node.js native add-on ... && \
npm i && \
echo Node.js native add-on successfully created. && \
echo Starting test ... && \
node add.js && \
echo Test successfully ended.