MOV SI,0300H
MOV DI,0400H
MOV AX,[SI]
INC SI
INC SI
MOV BX,[SI]
SUB AX,BX
JNC NOCARRY

MOV [DI],0001H

NOCARRY:
MOV [DI],0000H 

FINISH:
INC DI
MOV [DI],AX
HLT