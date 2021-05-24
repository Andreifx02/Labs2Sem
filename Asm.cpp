#include <iostream>

using namespace std;

int Calculate(int a, int b, int c, int y)
{
    int result;
    __asm
    {
        mov eax, b
        imul eax, y
        add eax, c
        neg eax
        mov ebx, 3
        imul ebx, a
        cdq
        idiv ebx
        mov result, eax

        mov eax, edx
        mov ecx, 2
        imul ecx
        idiv ebx

        cmp edx, 0
        je round_to_even

        add result, eax
        jmp m

        round_to_even :
        mov eax, result
        mov ebx, 2
        cdq
        idiv ebx
        add result, edx

        m :
    }

    return result;
}



int main()
{
    cout << Calculate(1, 2, 3, 4) << endl;
    cout << Calculate(4, 3, 9, 3) << endl;
}
