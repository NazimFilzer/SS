MOV SI, 500H   ; Load the address 500H into SI
MOV CL, [SI]   ; Load the value at address 500H into CL
DEC CL         ; Decrement CL

LOOP1:
    MOV SI, 500H  ; Load the address 500H into SI
    MOV CH, [SI]  ; Load the value at address 500H into CH
    DEC CH        ; Decrement CH

    INC SI        ; Increment SI

LOOP2:
    MOV AL, [SI]  ; Load the value at the updated address in SI into AL
    INC SI        ; Increment SI
    CMP AL, [SI]  ; Compare AL with the value at the updated address in SI
    JC CARRY      ; Jump to CARRY if AL is less than the value at the updated address

    XCHG AL, [SI] ; Exchange the values of AL and the value at the updated address in SI
    DEC SI        ; Decrement SI
    XCHG AL, [SI] ; Exchange the values of AL and the value at the updated address in SI
    INC SI        ; Increment SI

CARRY:
    DEC CH        ; Decrement CH
    JNZ LOOP2     ; Jump to LOOP2 if CH is not zero

    DEC CL        ; Decrement CL
    JNZ LOOP1     ; Jump to LOOP1 if CL is not zero

HLT             ; Halt the program
