
1. sudo bash -c 'echo "0" > /proc/sys/kernel/randomize_va_space'
2. gcc -g -z execstack -fno-stack-protector -o stack stack.c
3. gcc ./Badfile_Generators/generate_badfile<badfilenumber>.c
4. ./a.out
4. ./stack <badfilename>
5. for non-executable stack: gcc -g -fno-stack-protector -o stack stack.c

Turn on ASLR:
sudo bash -c 'echo "2" > /proc/sys/kernel/randomize_va_space'
