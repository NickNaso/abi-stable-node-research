#!/bin/bash          
echo Starting build process ...  && \
echo Build C library ...  && \
#rm -rf main.o && \
#rm -rf sum.o && \
#rm -rf libsum.a && \
#rm -rf main.o && \
#rm -rf libmath.a && \
gcc -c sum.c && \
ar -rc libsum.a sum.o && \
ranlib libsum.a && \
echo Build Go library ...  && \
go build -a -x -o libmath.a -buildmode=c-archive libmath.go && \
#ranlib libmath.a && \
echo Compile C program && \
gcc -c main.cc && \
gcc -o main main.o -pthread -L. -lmath && \
./main

