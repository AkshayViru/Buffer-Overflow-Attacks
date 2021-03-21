#!/usr/bin/bash
gcc -o bin1 -fno-stack-protector -z execstack printer.c
gcc -o bin4 -fno-stack-protector printer.c
cp bin1 bin2
cp bin1 bin3

chown root:root bin1 bin2 bin3 bin4
chmod +s bin1 bin2 bin3 bin4
echo 0 > /proc/sys/kernel/randomize_va_space