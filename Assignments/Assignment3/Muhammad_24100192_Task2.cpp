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
        cout << "Circle at (" << x << "," << y << ") with radius = " << radius << " has been destroyed" << endl;
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
    return 0;
}