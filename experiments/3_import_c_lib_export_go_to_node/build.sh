#!/bin/bash          
echo Starting build process ...
echo Build C library ...
gcc -c sum.c && \
ar -rc libsum.a sum.o
echo Build Go library ...
go build -a -x -o libmath.a -buildmode=c-archive libmath.go && \
echo Build Node.js native add-on ... && \
npm i && \
echo Node.js native add-on successfully created. && \
echo Starting test ... && \
node add.js && \
echo Test successfully ended.