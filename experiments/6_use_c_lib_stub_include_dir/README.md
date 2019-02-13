# Use C library stub in Go and and real library in Node.js setting the include dir

In this experiment I imported C library stub in **Go** then I used the function of the library in a **Go** function. After the export like a C static library I used it in a native add-on linking the real C library. In both environment I set the right include direcotry to make easier the usage of the libraries.
To run the experiment execute the following command:

`$ ./build.sh`

If you are on Unix system and you will have problem with permission try this:

`$ sudo chmod 755 build.sh`

If you are on **Windows** system try to replicate the commands that are on the build script reported below:

```
#!/bin/bash          
echo Starting build process ...  && \
echo Build C library ...  && \
gcc -c sum.c && \
ar -rcs libsum.a sum.o && \
ranlib libsum.a && \
gcc -c sum-stub.c && \
ar -rcs libsumstub.a sum-stub.o && \
ranlib libsumstub.a && \
echo Build Go library ...  && \
go build -a -x -o libmath.a -buildmode=c-archive libmath.go && \
npm i && \
echo Node.js native add-on successfully created. && \
echo Starting test ... && \
node add.js && \
echo Test successfully ended.