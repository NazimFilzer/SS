Assume CS:code, DS:data
data segment
msg1 db "Enter the first string : $"
msg2 db "The string is: $"
msg3 db "Length of the string is: $"
str1 db 20 dup(?)
data ends
code segment
start:
mov ax,data
mov DS,ax
mov cx,16h
lea dx,msg1
mov ah,09h
int 21h
lea dx,str1
mov bx,00
mov ah,3fh
int 21h
lea si,str1
xor ah,ah
add si,ax
mov byte ptr[si],'$'
lea dx,msg2
mov ah,09h
int 21h
lea dx,str1
mov ah,09h
int 21h
lea dx,msg3
mov ah,09h
int 21h
dec al
dec al
mov dl,al
add dl,30h
mov ah,02hint 21h
mov ah,4ch
int 21h
code ends
end start