;Shivank Tripathi - 20
;ISR Method
org 0000h
clr p0.7
mov ie, #85h
mov tmod, #10h
mov tl1, #0fah
mov th1, #0ffh
setb tr1
here:
sjmp here
org 001bh
clr tr1
clr tf1
cpl p1.0
mov p1, a
mov tl1, #0fah
mov th1, #0ffh
setb tr1
reti
end