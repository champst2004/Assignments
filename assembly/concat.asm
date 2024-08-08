section .data
    msg1 db 10d, "Enter first string: "
    len1 equ $-msg1

    msg2 db 10d, "Enter second string: "
    len2 equ $-msg2

    msg3 db 10d, "Concatinated string: "
    len3 equ $-msg3

    msg4 db 10d, " ", 0ah
    len4 equ $-msg4
section .bss

    %macro mac 4
    mov rax,%1
    mov rdi,%2
    mov rsi,%3
    mov rdx,%4

    syscall
    %endmacro

    str1 resb 25
    l1 resb 1

    str2 resb 25
    l2 resb 1

    str3 resb 50
    l3 resq 1



section .text
    global _start

_start:

mac 1, 1, msg1, len1
mac 0, 0, str1, 25
dec rax
mov [l1], al


mac 1, 1, msg2, len2
mac 0, 0, str2, 25
dec rax
mov[l2], al

call concat
mac 1, 1, msg4, len4
mac 60, 0, 0, 0

concat:
    mov rax, 0
    mov al, [l1]
    add al, [l2]
    mov [l3], rax
    mov rsi, str1
    mov rdi, str3

copy1:
    mov al, [rsi]
    mov [rdi], al
    inc rsi
    inc rdi
    dec byte[l1]
    jnz copy1
    mov rsi, str2

copy2:
    mov al, [rsi]
    mov [rdi], al
    inc rsi
    inc rdi
    dec byte[l2]
    jnz copy2

mac 1, 1, msg3, len3
mac 1, 1, str3, [l3]
RET
