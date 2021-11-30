#include <iostream>

using namespace std;

template <typename T>
T sum(T *arr, const int &size)
{
    T sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    const int size = 5;

    int a1[size] = {1, 1, 1, 1, 1};
    double a2[size] = {2.5, 1.0, 2.0, 1.0, 2.0};
    char a3[size] = {'a', '0', '1', 'a', 'b'};

    cout << "Sum of int array >> " << sum(a1, size) << endl;
    cout << "Sum of double array >> " << sum(a2, size) << endl;
    cout << "Sum of char array >> " << sum(a3, size) << endl;

    return 0;
}