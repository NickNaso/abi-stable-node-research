#!/bin/bash
echo Cleanup ... && \
rm -rf libsum.a && \
rm -rf sum.o && \
echo Cleanup successfully executed. && \
echo Starting build process ...
echo Build C library ...
gcc -c sum.c && \
ar -rc libsum.a sum.o
echo Build Node.js native add-on ... && \
npm i && \
echo Node.js native add-on successfully created. && \
echo Starting test ... && \
npm test && \
echo Test successfully ended.