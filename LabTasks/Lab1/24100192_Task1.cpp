#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n = 0;
    int spacing = 0;
    cout << "Enter number: ";
    cin >> n;
    spacing = n - 1;

    for (int i = 1; i <= n; i++)
    {
        cout << setfill(' ') << setw(n - i) << "";
        for (int j = 0; j < (2 * i) - 1; j++)
        {
            cout << "*";
        }
        cout << setfill(' ') << setw(n - 1) << "";
        cout << endl;
    }

    return 0;
}