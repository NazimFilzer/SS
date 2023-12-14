data SEGMENT
    MSG1 DW 10,13,'FOUND$'
    MSG2 DW 10,13,'NOT_FOUND$'
    ;ARR1 DB 03H,04H,01H,05H,07H
    ARR1 DB 5 DUP(?)
    
data ends

code SEGMENT
    ASSUME DS:data,CS:code
    
    START:
    MOV AX,data
    MOV DS,AX
    
    LEA SI,ARR1 
    MOV AH,01H
    
    ;GET INPUT
    INPUT:
    INT 21H
    CMP AL,0DH
    JE TERMINATE
    MOV [SI],AL
    INC SI
    JMP INPUT
    
    TERMINATE:
    
    LEA SI,ARR1      
            
    MOV CL,[SI] ;
    
    INC SI
   
    MOV BL,[SI]    ; KEY
        
    
    
    CHECK:
    INC SI
    MOV AL,[SI]
    CMP AL,BL
    JE FOUND
    LOOP CHECK
     
    NOT_FOUND:
    LEA DX,MSG2
    MOV AH,09H
    INT 21H
    HLT
    
    FOUND:
    LEA DX,MSG1
    MOV AH,09H
    INT 21H
    HLT
code ends
end START
    