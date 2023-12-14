data SEGMENT
    NOS EQU 03H
data ENDS

code SEGMENT
    ASSUME DS:data,CS:code
    MOV AX,DATA
    MOV DS,AX
    
    START:
 
    
    MOV CX,NOS  ; COUNTER 
    
    XOR DX,DX ;CLEAR
    
    MOV AX,01H   ; STORES FACT
  
    NEXT:
    MUL CX
    DEC CX
    JNZ NEXT
    
    HLT
code ENDS
END START
    
   
    
