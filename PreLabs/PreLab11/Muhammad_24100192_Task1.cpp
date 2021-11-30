#include <iostream>

using namespace std;

template <typename T>
T add(T a, T b)
{
    return a + b;
}

int main()
{
    double a;
    double b;

    cout << "Enter first real number >> ";
    cin >> a;

    cout << "Enter second real number >> ";
    cin >> b;

    cout << "Sum is " << add(a, b) << endl;
    return 0;
}