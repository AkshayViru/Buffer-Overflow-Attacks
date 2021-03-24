
1. sudo bash -c 'echo "0" > /proc/sys/kernel/randomize_va_space'
2. gcc -g -z execstack -fno-stack-protector -o stack stack.c
3. gcc generate_badfile1.c
4. ./stack
5. for non-executable stack: gcc -g -fno-stack-protector -o stack stack.c

ref:
https://github.com/npapernot/buffer-overflow-attack
https://samsclass.info/127/proj/p3-lbuf1.htm

Turn on ASLR:
sudo bash -c 'echo "2" > /proc/sys/kernel/randomize_va_space'
