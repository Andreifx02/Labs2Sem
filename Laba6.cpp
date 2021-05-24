#include <iostream>


extern "C" float _stdcall Arcsine(float x);
extern "C" float _stdcall CalculateSh(float x, float eps);

int main()
{
    /*float x;
    std::cin >> x;
    std::cout << Arcsine(x);*/
    float y,eps;
    std::cin >> y >> eps;
    std::cout << CalculateSh(y, eps);
}
