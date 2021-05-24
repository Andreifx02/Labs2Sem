#include <iostream>
#include <fstream>

extern "C" bool __stdcall IsMagicSquare(int** a, int n);

using namespace std;

int main() {

    int n;
    cin >> n;
    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    cout << "It " << (IsMagicSquare(a, n) ? "is" : "isn't") << " magic square.";
}
