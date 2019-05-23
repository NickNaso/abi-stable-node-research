# Use C/C++ library

In this experiment I created a **C** library and then import it on native add-on. To run the experiment execute the following command:

`$ ./build.sh`

If you are on Unix system and you will have problem with permission try this:

`$ sudo chmod 755 build.sh`

If you are on **Windows** system try to replicate the commands that are on the build script reported below:

```
#!/bin/bash          
echo Starting build process ...
echo Build C library ...
gcc -c sum.c && \
ar -rc libsum.a sum.o
echo Build Node.js native add-on ... && \
npm i && \
echo Node.js native add-on successfully created. && \
echo Starting test ... && \
node add.js && \
echo Test successfully ended.
```
