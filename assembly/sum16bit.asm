;Shivank Tripathi
;Roll no 20
;E5A6h + 30F1h = 11697h
mov r0, #0a6h
mov r1, #0e5h
mov r2, #0f1h
mov r3, #030h

mov a, r0
add a, r2
mov 45h, a

mov a, r1
addc a, r3
mov 44h, a

jnc done
mov 43h, #01h
done:
end