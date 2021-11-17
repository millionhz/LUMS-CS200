#include <iostream>

using namespace std;

class Integer
{
private:
    int x;

protected:
public:
    Integer(int in_x)
    {
        setX(in_x);
    }

    void setX(int in_x)
    {
        x = in_x;
    }

    int getX()
    {
        return x;
    }

    virtual void add(Integer *other_integer)
    {
        x += other_integer->x;
    }

    virtual void subtract(Integer *other_integer)
    {
        x -= other_integer->x;
    }

    virtual void multiply(Integer *other_integer)
    {
        x *= other_integer->x;
    }

    virtual void display()
    {
        cout << x << endl;
    }
};

class OrderedPair : public Integer
{
private:
    int y;

protected:
public:
    OrderedPair(int in_x, int in_y)
        : Integer(in_x)
    {
        y = in_y;
    }

    void add(Integer *other_integer)
    {
        Integer::add(other_integer);
        y += static_cast<OrderedPair *>(other_integer)->y;
    }

    void subtract(Integer *other_integer)
    {
        Integer::subtract(other_integer);
        y -= static_cast<OrderedPair *>(other_integer)->y;
    }

    void multiply(Integer *other_integer)
    {
        Integer::multiply(other_integer);
        y *= static_cast<OrderedPair *>(other_integer)->y;
    }

    void display()
    {
        cout << "(" << getX() << "," << y << ")" << endl;
    }
};

int main()
{
    OrderedPair op1(2, 3);
    OrderedPair op2(4, 6);

    Integer *ip1 = &op1;
    Integer *ip2 = &op2;

    ip1->display();

    ip1->multiply(ip2);
    ip1->display();

    return 0;
}