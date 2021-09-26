#include <iostream>
#include <cmath>

using namespace std;

class Circle
{
public:
    Circle()
    {
        setValues(0, 0, 1);
    }

    Circle(double _x, double _y)
    {
        setValues(_x, _y, 1);
    }

    Circle(double _x, double _y, double _radius)
    {
        setValues(_x, _y, _radius);
    }

    ~Circle()
    {
        cout << "Circle at (" << x << "," << y << ") with radius = " << radius << " is destroyed" << endl;
    }

    void setCenter(double _x, double _y)
    {
        setValues(_x, _y, radius);
    }

    void setRadius(double _radius)
    {
        setValues(x, y, _radius);
    }

    double getXCoordinate()
    {
        return x;
    }

    double getYCoordinate()
    {
        return y;
    }

    double getRadius()
    {
        return radius;
    }

    double getArea()
    {
        return M_PI * radius * radius;
    }

    double getCircumference()
    {
        return 2 * M_PI * radius;
    }

private:
    double x;
    double y;
    double radius;

    void setValues(double _x, double _y, double _radius)
    {
        x = _x;
        y = _y;
        radius = _radius;
    }
};

int main()
{
    Circle normal;

    cout << normal.getRadius() << endl;                                        //Should give you 1 :>
    cout << normal.getXCoordinate() << " " << normal.getYCoordinate() << endl; //Should give you 0,0

    cout << normal.getArea() << endl;          //Should give you pi * 1 = 3.14
    cout << normal.getCircumference() << endl; //Should give you pi * 2 = 6.something idk

    normal.setCenter(4, 5);
    cout << normal.getXCoordinate() << " " << normal.getYCoordinate() << endl; //Should give you 4,5

    normal.setRadius(5);
    cout << normal.getRadius() << endl; //Should give you 5

    cout << normal.getArea() << endl;          //Should give you 25 * pi
    cout << normal.getCircumference() << endl; //Should give you 10 * pi

    //You can run the same cases for the following objects too, using different test cases/values, as they utilize different constructors

    Circle notRound(1, 3);
    Circle circular(1, 3, 2);
    return 0;
}