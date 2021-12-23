#include <iostream>
#include <cmath>
using namespace std;

int reverse(int n, int d)
{
    if (n == 0)
    {
        return 0;
    }
    int x = (n - (n / 10) * 10) * d;
    return x + reverse(n / 10, d / 10);
}

int _calc(int n)
{
    if (!n)
    {
        return 0;
    }

    return 1 + _calc(n / 10);
}

int main()
{
    int number;
    cout << "Enter number >> ";
    cin >> number;

    cout << "Reversed number >> " << reverse(number, pow(10, _calc(number) - 1)) << endl;
}