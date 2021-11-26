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

int main()
{
    try
    {
        throw MyNullValueException();
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}