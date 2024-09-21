section .data
	msg db "Global Descriptor table register Base Address: "
	msglen equ $-msg
	msg1 db "Global Descriptor table register limit: "
	msg1len equ $-msg1
	msg2 db "Interrupt Descriptor table register Base Address: "
	msg2len equ $-msg2
	msg3 db "Interrupt Descriptor table register limit: "
	msg3len equ $-msg3
	msg4 db "Local Descriptor table register Base Address: "
	msg4len equ $-msg4
	msg5 db "Task register Base Address: "
	msg5len equ $-msg5
	msg6 db "Machine Status Word Base Address: "
	msg6len equ $-msg6
    msg7 db " ", 10
    msg7len equ $-msg7
	nl db 0Ah
 
section .bss
	gdtr resq 1
	gdtlimit resw 1
	idtr resq 1
	idtlimit resw 1
	ldtr resw 1
	tr resw 1
	msw resw 1
	temp resb 1

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
 
	rw 1,1,msg,msglen
	mov rsi,gdtr
	sgdt[rsi]
	call disp64
 
	rw 1,1,nl,1
 
	rw 1,1,msg1,msg1len
	mov rsi,gdtlimit
	call disp16
 
	rw 1,1,nl,1
 
	rw 1,1,msg2,msg2len
	mov rsi,idtr
	sidt[rsi]
	call disp64
 
	rw 1,1,nl,1
 
	rw 1,1,msg3,msg3len
	mov rsi,idtlimit
	call disp16
 
	rw 1,1,nl,1
 
	rw 1,1,msg4,msg4len
	mov rsi,ldtr
	sldt[rsi]
	call disp16
 
	rw 1,1,nl,1
 
	rw 1,1,msg5,msg5len
	mov rsi,tr
	str[rsi]
	call disp16
 
	rw 1,1,nl,1
 
	rw 1,1,msg6,msg6len
	mov rsi,msw
	smsw[rsi]
	call disp16

    rw 1,1,msg7,msg7len
	rw 60,0,0,0
 
disp16:	
    mov ax,word[rsi]
	mov bp,4
up1:    
    rol ax,4
	mov bx,ax
	and ax,0fh
	cmp al,09h
	jbe down1
	add al,07h
 
down1:  
    add al,30h
	mov byte[temp],al
	rw 1,1,temp,1
	mov ax,bx
	dec bp
	jnz up1
	ret
 
disp64:	
    mov rax,qword[rsi]
	mov bp,16
up2:    
    rol rax,4
	mov rbx,rax
	and rax,0fh
	cmp al,09h
	jbe down2
	add al,07h
 
down2:  
    add al,30h
	mov byte[temp],al
	rw 1,1,temp,1
	mov rax,rbx
	dec bp
	jnz up2
	ret