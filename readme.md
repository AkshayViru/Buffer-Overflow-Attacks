
1. sudo bash -c 'echo "0" > /proc/sys/kernel/randomize_va_space'
2. gcc -z execstack -fno-stack-protector -o stack stack.c

ref:
https://github.com/npapernot/buffer-overflow-attack
https://samsclass.info/127/proj/p3-lbuf1.htm
