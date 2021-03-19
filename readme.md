1. sudo bash -c 'echo "0" > /proc/sys/kernel/randomize_va_space'
2. gcc -g -z execstack -no-pie -o stack stack.c
3. gdb stack
4. checksec
5. break 8
6. run
7. info registers - check eip value
8. x/64x $esp - check where eip value is -> we need to overwrite this.

https://samsclass.info/127/proj/p3-lbuf1.htm
.
