section .data
	arr db 10h, 32h, 23h, 34h, 47h
	result db "The addition is: "
	len equ $-result
	
section .bss
	Result resw 1
	temp resw 1
	temp1 resb 1
	
	%macro rw 4
	mov rax, %1
	mov rdi, %2
	mov rsi, %3
	mov rdx, %4
	syscall
	%endmacro

section .text
	global _start

_start:
	rw 1, 1, result, len
	mov rsi, arr
	mov ax, 00h
	mov bx, 0h
	mov cx, 5
	
	up2:
		mov bl, byte[rsi]
		add ax, bx
		inc rsi
		dec cx
		jnz up2
		mov word[Result], ax
		mov ax, word[Result]
		mov bp, 4
	up:
		rol ax, 4
		mov bx, ax
		and ax, 0Fh
		cmp al, 09
		jbe down
		add al, 07
	down:
		add al, 30h
		mov byte[temp], al
		rw 1, 1, temp, 1
		mov ax, bx
		dec bp
		jnz up
		rw 60, 0, 0, 0
