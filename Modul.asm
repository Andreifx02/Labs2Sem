      .386
      .model flat
      .data
      .code
       PUBLIC _IsMagicSquare@8
_IsMagicSquare@8 PROC
       push   ebp
       mov    ebp, esp
	   push   ebx

       mov    ebx, [ebp+08h]
       mov    edx, [ebp+0Ch]

       mov ecx, edx
       rows:
       push ecx
       xor esi, esi
       mov ebp, [ebx + 4 * ecx - 4]
       mov ecx, edx
       inrow:
       add esi, [ebp + 4 * ecx - 4] 
       loop inrow
       pop ecx
       push esi
       loop rows

       mov ecx, edx
       cols:
       mov eax, ecx
       push ecx
       xor esi, esi
       mov ecx, edx
       incol:
       mov ebp, [ebx + 4 * ecx - 4]
       add esi, [ebp + 4 * eax - 4]
       loop incol
       pop ecx
       push esi
       loop cols

       mov ecx, edx
       mov eax, edx
       xor esi, esi
       mdiag: 
       mov ebp, [ebx + 4 * ecx - 4]
       add esi, [ebp + 4 * eax - 4]
       dec eax
       loop mdiag
       push esi

       mov ecx, edx
       mov eax, 0
       xor esi, esi
       pdiag: 
       mov ebp, [ebx + 4 * ecx - 4]
       add esi, [ebp + 4 * eax]
       inc eax
       loop pdiag
       push esi

       mov eax, 1
       mov ecx, edx 
       add ecx, edx
       inc ecx
       pop ebx
       check:
       pop esi 
       cmp esi, ebx
       je s
       mov eax, 0
       s:
       loop check
      
       pop    ebx
       pop    ebp
       ret    08h
_IsMagicSquare@8  ENDP
       end

