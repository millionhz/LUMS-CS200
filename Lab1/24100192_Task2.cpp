#include <iostream>

using namespace std;

int main()
{
    int a[10] = {0};
    int i;
    int n;

    cout << "Enter decimal number: ";
    cin >> n;

    // make bin
    for (i = 0; n > 0; i++)
    {
        a[i] = n % 2;
        n = n / 2;
    }

    cout << "The binary value is= ";
    for (int i = 9; i >= 0; i--)
    {
        cout << a[i];
    }

    return 0;
}