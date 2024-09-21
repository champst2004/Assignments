section .data
	msg1 db "Error",10
	len1 equ $-msg1
	msg2 db "File copied successfully",10
	len2 equ $-msg2
	
%macro mac 4
	mov rax, %1
	mov rdi, %2
	mov rsi, %3
	mov rdx, %4
	syscall
%endmacro

section .bss
	srcname resb 15
	srclen resq 1
	desname resb 15
	deslen resq 1
	buff resb 512
	bufflen resq 1
	
section .text
global _start
_start:

	pop r8
	cmp r8, 3
	jne err
	pop r8
	pop r8
	mov rsi, srcname

above: 
	mov al, [r8]
	cmp al, 00
	je next
	mov [rsi], al
	inc r8
	inc rsi
	jmp above

next:
	pop r8
	mov rsi, desname

above2:
	mov al, [r8]
	cmp al, 00
	je next2
	mov [rsi], al
	inc r8
	inc rsi
	jmp above2

next2:
	mac 2, srcname, 000000q, 0777q
	mov [srclen], rax	
	
	mac 0, [srclen], buff, 512
	mov [bufflen], rax
	
	mac 85, desname, 0777q, 0
	mac 2, desname, 2, 0777q
	mov [deslen], rax
	
	mac 1, [deslen], buff, [bufflen]
	
	mac 3, [deslen],0,0
	mac 3, [srclen],0,0
	
	mac 1,1,msg2,len2
	jmp end
	
err:
	mac 1,1,msg1,len1
	
end:
	mac 60,0,0,0