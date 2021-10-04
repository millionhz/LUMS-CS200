#include <iostream>
#include <math.h>

using namespace std;

class Polygon
{
private:
    double *coordinates;
    double *x;
    double *y;
    int sides;
    int total_points;

    double distance(double x1, double y1, double x2, double y2)
    {
        // 0 = x
        // 1 = y
        return sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
    }

    double *getX(double *coordinates)
    {
        double *x = new double[sides];
        int index = 0;
        for (int i = 0; i < total_points; i += 2)
        {
            x[index] = coordinates[i];
            index++;
        }

        return x;
    }

    double *getY(double *coordinates)
    {
        double *y = new double[sides];
        int index = 0;
        for (int i = 1; i < total_points; i += 2)
        {
            y[index] = coordinates[i];
            index++;
        }

        return y;
    }

    double *initCoordinateArray()
    {
        return new double[total_points];
    }

    double *addPointsToCoordinateArray(double *_coordinates)
    {
        for (int i = 0; i < total_points; i++)
        {
            coordinates[i] = _coordinates[i];
        }
        return coordinates;
    }

    void initSquare()
    {
        sides = 4;

        total_points = sides * 2;
        coordinates = initCoordinateArray();
        double _coordinates[] = {0, 0, 0, 1, 1, 1, 1, 0};
        coordinates = addPointsToCoordinateArray(_coordinates);

        x = getX(coordinates);
        y = getY(coordinates);
    }

public:
    Polygon()
    {
        initSquare();
    }

    Polygon(double *_coordinates, int _sides)
    {
        if (_sides < 2 || (_sides * 2) % 2 != 0)
        {
            initSquare();
        }
        else
        {
            sides = _sides;

            total_points = _sides * 2;
            coordinates = initCoordinateArray();
            coordinates = addPointsToCoordinateArray(_coordinates);

            x = getX(coordinates);
            y = getY(coordinates);
        }
    }

    void printCoordinates()
    {
        for (int i = 0; i < total_points; i += 2)
        {
            cout << "(" << coordinates[i] << ", " << coordinates[i + 1] << ")" << endl;
        }
    }

    ~Polygon()
    {
        delete[] coordinates;
        delete[] x;
        delete[] y;
    }

    double perimeter()
    {
        double perimeter = 0;
        for (int i = 0; i < total_points - 2; i += 2)
        {
            perimeter += distance(coordinates[i], coordinates[i + 1], coordinates[i + 2], coordinates[i + 3]);
        }
        perimeter += distance(coordinates[(total_points)-2], coordinates[(total_points)-1], coordinates[0], coordinates[1]);
        return perimeter;
    }
};

int main()
{
    Polygon square;
    cout << square.perimeter() << endl;

    double triangle_coordinates[] = {0, 0, 1, 0, 0, 1};
    Polygon triangle(triangle_coordinates, 3);
    cout << triangle.perimeter() << endl;

    return 0;
}