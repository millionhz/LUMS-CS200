#include <iostream>
#include <exception>

using namespace std;

class MyOutOfBoundException : public exception
{
public:
    const char *what() const noexcept
    {
        return "Index out of bound";
    }
};

class MyDivideByZeroException : public exception
{
public:
    const char *what() const noexcept
    {
        return "Division by 0 is not allowed";
    }
};

class MyNullValueException : public exception
{
public:
    const char *what() const noexcept
    {
        return "Null Pointer passed";
    }
};

double divide(int *arr, int len, int a, int b)
{
    if ((a >= len || a < 0) || (b >= len || b < 0))
    {
        throw MyOutOfBoundException();
    }
    else if (!arr)
    {
        throw MyNullValueException();
    }
    else if (arr[b] == 0)
    {
        throw MyDivideByZeroException();
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
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }

    delete arr;

    return 0;
}