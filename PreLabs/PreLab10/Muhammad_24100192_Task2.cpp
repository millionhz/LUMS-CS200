#pragma GCC diagnostic ignored "-Wdeprecated"

#include <iostream>
#include <exception>

using namespace std;

class MyException : public exception
{
private:
    const char *message = "MyException thrown";

public:
    const char *what() const noexcept
    {
        return message;
    }
};

int main()
{
    try
    {
        throw MyException();
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}