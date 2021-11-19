#include <iostream>

using namespace std;

class Integer
{
private:
    int number;

protected:
public:
    Integer(int in_x)
    {
        setNumber(in_x);
    }

    void setNumber(int in_x)
    {
        number = in_x;
    }

    int getNumber()
    {
        return number;
    }

    virtual void add(Integer *other_integer)
    {
        number += other_integer->number;
    }

    virtual void subtract(Integer *other_integer)
    {
        number -= other_integer->number;
    }

    virtual void multiply(Integer *other_integer)
    {
        number *= other_integer->number;
    }

    virtual void display()
    {
        cout << number << endl;
    }
};

int main()
{
    return 0;
}