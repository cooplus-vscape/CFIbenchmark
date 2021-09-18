# CFI_benchmark


Here is a Sample Usage on LLVM-CFI:


```
clang++ -o bm -flto -fsanitize=cfi -fvisibility=default benchmark.cpp

(vvv) ➜  ~ ./bm
D3-func
obj start at 0x19ed070 # D3 obj
vptr is 0x400b28
obj start at 0x19ed0b0 # D2 obj
vptr is 0x400ba8
change vptr to:0x400b28 # change D2 obj vptr toward D3's vtable
vptr is 0x400b28
D3-func                 # Control Flow Distort
```
