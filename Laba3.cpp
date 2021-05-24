#include <iostream>
#include <vector>

unsigned int Check(unsigned int a, unsigned int b, unsigned int c) {
    __asm
    {
        mov ecx, 1
        mov eax, a
        add eax, b
        jc m
        cmp eax, c
        jg m
        mov ecx, 0
        m:
        mov ebx, b
        add ebx, c
        jc n
        cmp ebx, a
        jg n
        mov ecx, 0
        n:
        mov edx, a
        add edx, c
        jc h
        cmp edx, b
        jg h
        mov ecx, 0
        h:
        mov eax, ecx
    }
}

int main()
{
    std::cout << Check(3000000000, 3000000000, 2000000000);
    
    int* result = new int[3]{ 0, 0, 0 };
    int n = 4;
    int* a = new int[n]{ 2000001,-3000000,-1000000,2 };
    int* b = new int[n]{ 2000000,2000000,-2000000,1 };
    //int* a = new int[2]{ 2,-4 };
    //int* b = new int[2]{ -3,-1 };

    __asm 
    {
        pushad

        mov edi, a
        mov esi, b

        XOR ECX, ECX
        mov edx,0
    ForBegin1:
        CMP ECX, n
        JE ForEnd1

            mov ebx, dword ptr[edi]
        add edi, 4  

            mov eax, dword ptr[esi]
        add esi, 4    

        imul ebx    

        mov ebx, result
        add dword ptr[ebx], eax; [ebx + N] = [ebx + N] + eax;
        adc dword ptr[ebx + 4], edx
        adc dword ptr[ebx + 8], 0
        INC ECX
        JMP ForBegin1;
    ForEnd1:

        popad
    }

    std::cout << std::endl;
    std::cout << *result << std::endl;
    std::cout << "carry: " << result[2] << std::endl;
    std::cout << "sign: " << result[1] << std::endl;
    std::cout << std::hex << result[2] << " " << std::hex <<  result[1] << " " << std::hex << result[0] << std::endl;

    /*std::cout << "Press any key to continue...";
    std::cin.get();*/
}
