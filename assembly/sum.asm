section .data
    msg db "The sum is:", 0ah
    msglen equ $-msg
    num1 db 11H
    num2 db 22h

section .bss
    sum resb 1
    temp resb 1
section .text
    global _start

_start:
    mov rax, 1
    mov rdi, 1
    mov rsi, msg
    mov rdx, msglen
    syscall

mov al, byte[num1]
add al, byte[num2]
mov byte[sum], al
mov bp, 2
up:rol al,4
    mov bl, al
    and al, 0Fh
    cmp al,09
        jbe down
            add al, 07h
                down: Add al, 30h
            Mov byte[temp], al
            mov rax, 1
            mov rdi, 1
            mov rsi, temp
            mov rdx, 1
            syscall
