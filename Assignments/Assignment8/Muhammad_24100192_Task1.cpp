#include <iostream>
#include <cmath>

using namespace std;

class Shape
{
private:
protected:
    int parameter;

public:
    virtual void area() = 0;
};

// Right-angled triangle with two equal sides
class RightAngledTriangle : public Shape
{
private:
    double getArea()
    {
        //double base_height = sqrt((parameter * parameter) / 2);
        return (parameter * parameter) / 4;
    }

protected:
public:
    RightAngledTriangle(int hypotenuse)
    {
        parameter = hypotenuse;
    }

    void area()
    {
        cout << "Right-angled triangle with hypotenuse " << parameter << " has an area of " << getArea() << endl;
    }
};

class Square : public Shape
{
private:
    double getArea()
    {
        return parameter * parameter;
    }

protected:
public:
    Square(int side_len)
    {
        parameter = side_len;
    }

    void area()
    {
        cout << "Square with side " << parameter << " has an area of " << getArea() << endl;
    }
};

class Circle : public Shape
{
private:
    double getArea()
    {
        return M_PI * parameter * parameter;
    }

protected:
public:
    Circle(int radius)
    {
        parameter = radius;
    }

    void area()
    {
        cout << "Circle with radius " << parameter << " has an area of " << getArea() << endl;
    }
};

int main()
{
    size_t size = 1000;
    Shape *myShapes[size];

    for (size_t i = 0; i < size; i++)
    {
        int num = rand() % 3;

        if (num == 2)
        {
            myShapes[i] = new Circle(rand() % 20 + 1);
        }
        else if (num == 1)
        {
            myShapes[i] = new Square(rand() % 20 + 1);
        }
        else
        {
            myShapes[i] = new RightAngledTriangle(rand() % 10 + 1);
        }
    }

    for (size_t i = 0; i < size; i++)
    {
        myShapes[i]->area();
    }

    return 0;
}