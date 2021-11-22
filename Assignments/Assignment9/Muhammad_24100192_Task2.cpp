#include <iostream>

using namespace std;

struct MyException
{
    string text;

    MyException(string s)
    {
        text = s;
    }
};

double divide(int *arr, int len, int a, int b) throw(MyException)
{
    if ((a >= len || a < 0) || (b >= len || b < 0))
    {
        throw MyException("Index out of bound");
    }
    else if (!arr)
    {
        throw MyException("Null Pointer passed");
    }
    else if (arr[b] == 0)
    {
        throw MyException("Division by 0 is not allowed");
    }

    return arr[a] / static_cast<double>(arr[b]);
}

int main()
{
    int size;
    int a;
    int b;

    cout << "Enter length of array >> ";
    cin >> size;

    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter element " << i << " >> ";
        cin >> arr[i];
    }

    cout << "Enter index of dividend >> ";
    cin >> a;

    cout << "Enter index of divisor >> ";
    cin >> b;

    try
    {
        double ans = divide(arr, size, a, b);

        cout << "Answer: " << ans << endl;
    }
    catch (MyException e)
    {
        cout << e.text << endl;
    }

    delete arr;

    return 0;
}