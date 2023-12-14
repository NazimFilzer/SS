data SEGMENT
    MSG1 db 10,13,'Enter a string: $'
    MSG2 db 10,13,'It is a palindrome$'
    MSG3 db 10,13,'Not a Palindrome$'
    STR1 db 50 dup(0)
data ENDS

code SEGMENT
    ASSUME CS:code, DS:data
    
    START:
    MOV AX, data
    MOV DS, AX
    
    LEA DX, MSG1
    MOV AH, 09H
    INT 21H
    
    LEA SI, STR1
    LEA DI, STR1
    MOV AH, 01H
    
    ; Input string
    NEXT:
    INT 21H
    CMP AL, 0DH
    JE TERMINATE
    MOV [DI], AL
    INC DI
    JMP NEXT
    
    TERMINATE:
    MOV AL,'$'
    MOV [DI], AL
    
    
    DOTHIS:
    DEC DI
    MOV AL, [SI]
    CMP [DI],AL
    JNE NOTPAL
    INC SI
    CMP SI,DI
    JL DOTHIS
    
     
    PALIN:
    MOV AH, 09H
    LEA DX, MSG2
    INT 21H
    JMP XX
    
    NOTPAL:
    MOV AH, 09H
    LEA DX, MSG3
    INT 21H 
    
    XX:
    MOV AH, 4CH
    INT 21H 
    
code ENDS
END START
