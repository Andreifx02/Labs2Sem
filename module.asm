.586

.model flat
.data

eps dd ?
temp dd ?
res dd ?
sqrx dd ?
denom dd 1
one dd 1



.code
_Arcsine@4 proc
fld dword ptr [esp + 4]
fld dword ptr [esp + 4]
fmul st(0), st(1); 
fld1; 1 sin2 sin 
fsub st(0),st(1); cos2 sin2 sin 
fsqrt; cos sin2 sin 
fxch st(1)
fxch st(2)
fxch st(1)
fpatan
frndint

ret 4
_Arcsine@4 endp

_CalculateSh@8 proc

finit
fld dword ptr[esp + 4]
fld dword ptr[esp + 4]
fst temp
fst res
fmul
fst sqrx
fld dword ptr[esp+8]
fst eps
fcompp
ja n

m:

fld temp
fld sqrx
fmul
fild denom
fild one
fadd
fist denom
fdiv
fild denom
fild one
fadd
fist denom
fst temp
fld res
fadd
fst res


fld temp
fld eps
fcompp
jb m

n:
fld res
ret 8
 
_CalculateSh@8 endp
end