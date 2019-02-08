# Export Go function to Node.js

In this experiment I create a **Go** function that I subsequently export like C static library. After this first process I import the library in a native add-on. To run the experiment execute the following command:

`$ ./build.sh`

If you are on Unix system and you will have problem with permission try this:

`$ sudo chmod 755 build.sh`

If you are on **Windows** system try to replicate the command that are on the build script reported below:

```
#!/bin/bash          
echo Starting build process ...
echo Build Go library ...
go build -a -x -o libmath.a -buildmode=c-archive libmath.go && \
echo Build Node.js native add-on ... && \
npm i && \
echo Node.js native add-on successfully created. && \
echo Starting test ... && \
node add.js && \
echo Test successfully ended.
```
