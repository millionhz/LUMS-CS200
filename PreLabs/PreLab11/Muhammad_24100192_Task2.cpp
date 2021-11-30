#include <iostream>

using namespace std;

template <typename T>
T add(T a, T b)
{
    return a + b;
}

template <typename T, typename U>
double add(T a, U b)
{
    return a + b;
}

int main()
{
    int a = 1, b = 2;
    double c = 2.5, d = 3.4;

    cout << "sum(a, b) = " << add(a, b) << endl;
    cout << "sum(c, d) = " << add(c, d) << endl;
    cout << "sum(a, c) = " << add(a, c) << endl;
    cout << "sum(d, b) = " << add(d, b) << endl;

    return 0;
}