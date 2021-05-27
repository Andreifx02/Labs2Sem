#include <iostream>

extern "C" bool __stdcall IsPalindrom(char* s);
extern "C" int __stdcall DeleteBracers(char* s, int length);

int main()
{

    char* a = new char[200];
    std::cin.getline(a, 200);
    int Length = strlen(a);
    a[Length] = '.';
    a[Length + 1] = '\0';
    std::cout << IsPalindrom(a);
    char* s = new char[200];
    int length;
    std::cin >> s;
    int Length = strlen(s);
    std::cout << DeleteBracers(s, Length);         
}
