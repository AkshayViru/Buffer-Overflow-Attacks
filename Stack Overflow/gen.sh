#!/bin/bash 

# To add characters to badfile.txt
# arg[1] number of A are added

python3 -c 'print("A"*'$1')' > badfile_1.txt
