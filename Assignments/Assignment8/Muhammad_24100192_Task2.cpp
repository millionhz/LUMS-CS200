#include <iostream>
#include <cmath>

using namespace std;

class Shape
{
private:
protected:
    int num_of_parameters;

public:
    virtual void area() = 0;
    virtual void perimeter() = 0;

    virtual ~Shape() {}
};

class Circle : public Shape
{
private:
    int *arr;

    double getArea()
    {
        return M_PI * arr[2] * arr[2];
    }

    double getPerimeter()
    {
        return 2 * M_PI * arr[2];
    }

protected:
public:
    Circle(int x, int y, int radius)
    {
        num_of_parameters = 3;
        arr = new int[num_of_parameters];

        arr[0] = x;
        arr[1] = y;
        arr[2] = radius;
    }

    void area()
    {
        cout << "Area of Circle is " << getArea() << endl;
    }

    void perimeter()
    {
        cout << "Perimenter of Circle is " << getPerimeter() << endl;
    }

    ~Circle()
    {
        delete arr;
        arr = nullptr;
    }
};

class Square : public Shape
{
private:
    int *arr;

    double getArea()
    {
        int side = arr[0] - arr[3];
        return side * side;
    }

    double getPerimeter()
    {
        int side = arr[0] - arr[3];
        return 4 * abs(side);
    }

protected:
public:
    Square(int upper_right_x, int upper_right_y, int lower_left_x, int lower_left_y)
    {
        num_of_parameters = 4;
        arr = new int[num_of_parameters];

        arr[0] = upper_right_x;
        arr[1] = upper_right_y;
        arr[2] = lower_left_x;
        arr[3] = lower_left_y;
    }

    void area()
    {
        cout << "Area of Square is " << getArea() << endl;
    }

    void perimeter()
    {
        cout << "Perimenter of Square is " << getPerimeter() << endl;
    }

    ~Square()
    {
        delete arr;
        arr = nullptr;
    }
};

class RightAngledTriangle : public Shape
{
private:
    int *arr;

    double getArea()
    {
        int base_height = arr[0] - arr[2]; //x1 - x2
        return 0.5 * base_height * base_height;
    }

    double getPerimeter()
    {
        int base_height = arr[0] - arr[2]; //x1 - x2
        return 2 * abs(base_height) + sqrt(((arr[4] - arr[2]) * (arr[4] - arr[2])) + ((arr[5] - arr[3]) * (arr[5] - arr[3])));
    }

protected:
public:
    RightAngledTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
    {
        num_of_parameters = 6;
        arr = new int[num_of_parameters];

        arr[0] = x1;
        arr[1] = y1;
        arr[2] = x2;
        arr[3] = y2;
        arr[4] = x3;
        arr[5] = y3;
    }

    void area()
    {
        cout << "Area of Right-angled Triangle is " << getArea() << endl;
    }

    void perimeter()
    {
        cout << "Perimenter of Right-angled Triangle is " << getPerimeter() << endl;
    }

    ~RightAngledTriangle()
    {
        delete arr;
        arr = nullptr;
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
            myShapes[i] = new Circle(0, 0, rand() % 20 + 1);
        }
        else if (num == 1)
        {
            myShapes[i] = new Square(0, 0, 4, 4);
        }
        else
        {
            myShapes[i] = new RightAngledTriangle(0, 0, 4, 4, 0, 8);
        }
    }

    for (size_t i = 0; i < size; i++)
    {
        myShapes[i]->area();
        myShapes[i]->perimeter();
    }

    for (size_t i = 0; i < size; i++)
    {
        delete myShapes[i];
    }

    return 0;
}