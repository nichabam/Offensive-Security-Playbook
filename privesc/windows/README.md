## EXE

C

```
x86_64-w64-mingw32-gcc file.c -o program.exe
```

C++

```
x86_64-w64-mingw32-g++ file.cpp -o program.exe
```

## DLL

C

```
x86_64-w64-mingw32-gcc -shared file.c -o payload.dll
```

C++

```
x86_64-w64-mingw32-g++ -shared file.c -o payload.dll
```