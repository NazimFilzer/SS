data segment
    arr1 db 04h,01h,05h,03h,04h
    even db ?
    odd db ?
    
data ends

code segment
    assume ds:data,cs:code
    
    start:
    mov ax,data
    mov ds,ax
    
    lea si,arr1
                  
  
    
    mov cl,[arr1] ;count
    inc si  
    
    mov bl,02h
    
    next:
    xor ah,ah  ; imp
    mov al,[si]  ;first ele
    div bl
    cmp ah,00h
    je inc_even: 
    add odd,01h 
    jmp next_ele
    
   
    
    inc_even:
    add even,01h 
    
    next_ele:
    inc si
    dec cl
    jnz next 
    
    mov al,odd
    mov ah,even
    
    hlt
   
code ends
end start
    