1. sudo bash -c 'echo "2" > /proc/sys/kernel/randomize_va_space'
2. gcc stack.c -o stack -m32 -fno-stack-protector -z execstack 
3. Install gef- wget -q -O- https://github.com/hugsy/gef/raw/master/scripts/gef.sh | sh
4. gdb stack
5. checksec

