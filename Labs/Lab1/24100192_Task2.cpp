#include <iostream>

using namespace std;

int main()
{
    int size = 8;
    int a[size] = {0};
    int n = 0;

    cout << "Enter decimal number: ";
    cin >> n;

    // make bin
    for (int i = 0; n > 0; i++)
    {
        a[i] = n % 2;
        n = n / 2;
    }

    // print bin
    cout << "The binary value is= ";
    for (int i = size - 1; i >= 0; i--)
    {
        cout << a[i];
    }

    return 0;
}