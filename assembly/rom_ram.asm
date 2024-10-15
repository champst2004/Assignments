;Shivank Tripathi
;Roll no 20
mov r3, #05h
mov dptr, #001ah
mov r0, #45h
up:
clr a ; mov a, #00h
movc a, @a+dptr
mov @r0, a
inc dptr
inc r0
djnz r3, up
end