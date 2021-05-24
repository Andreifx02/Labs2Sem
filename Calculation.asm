.386
      .model flat
      .data
      .code
       PUBLIC _Calculation@16
_Calculation@16 PROC
       push   ebp
       mov    ebp, esp
	   push   ebx

       mov eax, [ebp + 12]
        imul eax, [ebp + 20]
        add eax, [ebp + 16]
        neg eax
        mov ebx, 3
        imul ebx, [ebp + 8]
        cdq
        idiv ebx
        mov esi, eax

        mov eax, edx
        mov ecx, 2
        imul ecx
        idiv ebx

        cmp edx, 0
        je round_to_even

        add esi, eax
        jmp m

        round_to_even :
        mov eax, esi
        mov ebx, 2
        cdq
        idiv ebx
        add esi, edx

        m :

        mov eax, esi

       pop    ebx
       pop    ebp
       ret    16
_Calculation@16  ENDP
       

PUBLIC _Check@12
_Check@12 PROC
    
        mov ecx, 1
        mov eax, [esp + 4]
        mov edi, [esp + 8]
        add eax, edi
        jc m
        mov esi, [esp + 12]
        cmp eax, esi
        jg m
        mov ecx, 0
        m:
        mov ebx, edi
        add ebx, esi
        jc n
        cmp ebx, [esp + 4]
        jg n
        mov ecx, 0
        n:
        mov edx, [esp + 4]
        add edx, esi
        jc h
        cmp edx, edi
        jg h
        mov ecx, 0
        h:
        mov eax, ecx
        ret 12
_Check@12 ENDP
      

PUBLIC _MultiplicationInArray@16
_MultiplicationInArray@16 PROC

   pushad

        mov edi, [esp + 4]
        mov esi, [esp + 8]

        XOR ECX, ECX
        mov edx,0
    ForBegin1:
        CMP ECX, [esp + 16]
        JE ForEnd1

            mov ebx, dword ptr[edi]
        add edi, 4  

            mov eax, dword ptr[esi]
        add esi, 4    

        imul ebx    

        mov ebx, [esp + 12]
        add dword ptr[ebx], eax; [ebx + N] = [ebx + N] + eax;
        adc dword ptr[ebx + 4], edx
        adc dword ptr[ebx + 8], 0
        INC ECX
        JMP ForBegin1;
    ForEnd1:
        
        popad


_MultiplicationInArray@16 ENDP
       end