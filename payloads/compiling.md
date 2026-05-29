## Arhictecture
```
uname -a
uname -m
file /bin/bash
ldd --version 2>/dev/null
```

## Compiling Exploits
```
gcc exploit.c -o exploit
```

### If target is 32-bit
```
gcc exploit.c -o exploit -m32
```

### If old code gives implicit function declaration errors
```
gcc exploit.c -o exploit -m32 -Wno-error=implicit-function-declaration
```

### If target gives GLIBC_x.xx not found
```
gcc exploit.c -o exploit -m32 -Wno-error=implicit-function-declaration -static
```

### Check result
```
file exploit
ldd exploit
```