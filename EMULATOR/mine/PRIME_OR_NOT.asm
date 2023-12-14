DATA SEGMENT
    PRIME_MSG DW 10, 13,'prime$'
    NOT_PRIME DW 10, 13,'NOT PRIME$'
    NUMBER DB 09H  
    ;RESULT DB ?
DATA ENDS

CODE SEGMENT
    ASSUME DS:DATA, CS:CODE
    START:
    MOV AX, DATA
    MOV DS, AX 
    
           
    ;LEA SI,NUMBER
    ;MOV BL, [SI]
    
    MOV BL,NUMBER
    
    MOV CL, 02H
    
    CHECK:
    CMP BL, CL
    JZ PRIME
    ;XOR DX, DX   ; Clear DX before division 
    MOV AH,00H
    MOV AL,BL
    DIV CL
    
    CMP AH, 00H    ; Check if remainder is zero
    JZ NOT_PRIMEP
    INC CL
    JMP CHECK
      
      
    NOT_PRIMEP:
    MOV DL,00H
    JMP ENDPR 
    
    PRIME:
    MOV DL,01
   

    ENDPR:
    HLT

CODE ENDS
END START