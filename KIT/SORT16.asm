MOV SI,0300H
MOV BX,[SI]
DEC BX

OUTER: 
MOV SI,0300H 
MOV CX,[SI]
DEC CX
INC SI


INNER:
MOV AX,[SI]
INC SI
INC SI
CMP AX,[SI]
JC CARRY  

XCHG AX,[SI]
DEC SI 
DEC SI
XCHG AX,[SI] 

INC SI
INC SI

CARRY:
DEC CX
JNZ INNER 
DEC BX
JNZ OUTER
HLT
