#include <iostream>

using namespace std;

int main()
{

    int m, n, gcd;
    cout << "Enter m: ";
    cin >> m;

    cout << "Enter n: ";
    cin >> n;

    if (n > m)
    {
        int temp = n;
        n = m;
        m = temp;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (m % i == 0 && n % i == 0)
        {
            gcd = i;
        }
    }

    cout << "GCD is: " << gcd;

    return 0;
}