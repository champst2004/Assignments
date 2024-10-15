;Shivank Tripathi - 20
;Polling Method
org 0000h
mov tmod, #10h
mov a, #00h
clr p0.7
again:
mov th1, #0ffh
mov tl1, #0f0h
setb tr1
here:
jnb tf1, here
clr tr1
clr tf1
cpl p1.0
sjmp again
end