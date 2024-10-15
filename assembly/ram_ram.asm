;Shivank Tripathi
;Roll no 20
mov r3, #2h
mov r0, #15h
mov r1, #25h
up:
mov a, @r0
mov @r1, a
inc r0
inc r1
djnz r3, up
end
