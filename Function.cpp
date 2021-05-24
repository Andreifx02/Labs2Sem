#include <iostream>

extern "C" int __stdcall Calculation(int, int, int, int);
extern "C" int __stdcall Check(unsigned int a, unsigned int b, unsigned int c);
extern "C" int __stdcall MultiplicationInArray(int* a, int* b, int* result,int n );

int main()
{
    std::cout << Calculation(1, 2, 3, 4);
    std::cout << Check(3000000000, 3000000000, 2000000000);
    int* result = new int[3]{ 0, 0, 0 };
    int n = 4;
    int* a = new int[n] { 2000001, -3000000, -1000000, 2 };
    int* b = new int[n] { 2000000, 2000000, -2000000, 1 };

    std::cout << std::endl;
    std::cout << *result << std::endl;
    std::cout << "carry: " << result[2] << std::endl;
    std::cout << "sign: " << result[1] << std::endl;
    std::cout << std::hex << result[2] << " " << std::hex << result[1] << " " << std::hex << result[0] << std::endl;

    /*std::cout << "Press any key to continue...";
    std::cin.get();*/
}
