.386
.model flat
PUBLIC _IsPalindrom@4
.data
.code

_IsPalindrom@4 PROC
mov edi, dword ptr[esp + 4]
mov esi, dword ptr[esp + 4]
mov eax, '.'
XOR ecx, ecx

cycle:

scasb
je break
inc ecx
jmp cycle
break:

dec edi
dec edi

cycle2:
cmpsb 
jne false
dec ecx
cmp ecx, 0
je true
dec edi
dec edi
jmp cycle2

true:
mov eax, 1
jmp ending

false:
mov eax, 0
ending:
ret 4
_IsPalindrom@4  ENDP

_DeleteBracers@8 PROC

push edi

mov edi,[esp + 8]
mov ecx,[esp + 12]

mov esi, 0
mov ebx, 0


cycle2:
sub esi, ebx
mov ebx, 2
mov eax, '('
cycle1:


inc esi
scasb
jne next

m:
mov eax, ')'
dec ecx
cmp ecx,0
je exit
inc ebx
inc esi





scasb
je cycle2
jmp m

next:

loop cycle1
exit:
mov eax, esi

pop edi

ret 8
_DeleteBracers@8  ENDP
end