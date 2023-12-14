data segment
    num db ?
    msg1 dw 10,13,'Enter charater - $'
data ends


code segment 
    assume cs:code,ds:data
    
    start:
    mov ax,data            
    mov ds,ax 
    
    lea si,msg1
    mov ah,09h
    int 21h
    
    mov ah,01h
    int 21h
    mov num,al
    

    ;convert num to decimal
    mov dh,num
    hlt
    
code ends
end start
    
    
    
    
