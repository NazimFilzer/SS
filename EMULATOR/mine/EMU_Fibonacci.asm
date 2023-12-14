DATA SEGMENT
    NUM EQU 7
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE,DS:DATA
    
    START:
    MOV AX,DATA
    MOV DS,AX
             
    MOV AL,00H         
    MOV SI,500H
    MOV [SI],AL
    INC SI
    MOV AL,01H
    MOV [SI],AL
        
    MOV CX,NUM
    SUB CX,2 
  
    
    NEXT:
    MOV AL,[SI-1]
    ADD AL,[SI]
    INC SI
    MOV [SI],AL
    DEC CX
    JNZ NEXT   
HLT

CODE ENDS
END START
    