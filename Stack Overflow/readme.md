
1. sudo bash -c 'echo "0" > /proc/sys/kernel/randomize_va_space'
2. gcc -g -z execstack -fno-stack-protector -o stack stack.c
3. gcc ./Badfile_Generators/generate_badfile<badfilenumber>.c
4. ./a.out
4. ./stack <badfilename>
5. for non-executable stack: gcc -g -fno-stack-protector -o stack stack.c

ref:
q6: http://cs.iit.edu/~khale/class/security/s20/handout/lab2.html
https://github.com/npapernot/buffer-overflow-attack
https://samsclass.info/127/proj/p3-lbuf1.htm
https://github.com/z3tta/Exploit-Exercises-Protostar/blob/master/13-Heap0.md
q7: https://www.youtube.com/watch?v=Gu_JGaWpcn4

Turn on ASLR:
sudo bash -c 'echo "2" > /proc/sys/kernel/randomize_va_space'
