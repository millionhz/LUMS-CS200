#pragma GCC diagnostic ignored "-Wdeprecated"

#include <iostream>
#include <exception>

using namespace std;

class DivideByZero : public exception
{
private:
public:
    const char *what() const noexcept
    {
        return "Division by 0 is not allowed";
    }
};

double divide(int a, int b) throw(exception)
{
    if (b == 0)
    {
        throw DivideByZero();
    }

    return a / static_cast<double>(b);
}

int main()
{
    int a;
    int b;

    cout << "Enter index of dividend >> ";
    cin >> a;

    cout << "Enter index of divisor >> ";
    cin >> b;

    try
    {
        double ans = divide(a, b);

        cout << "Answer >> " << ans << endl;
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}
