#include <iostream>
#include <math.h>

using namespace std;

class Polygon
{
private:
    double *coordinates;
    int total_points;

    double distance(double x1, double y1, double x2, double y2)
    {
        // 0 = x
        // 1 = y
        return sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
    }

    double *initCoordinateArray()
    {
        return new double[total_points];
    }
    void deleteCoordinateArray()
    {
        delete[] coordinates;
    }

    void addPointsToCoordinateArray(double *_coordinates)
    {
        for (int i = 0; i < total_points; i++)
        {
            coordinates[i] = _coordinates[i];
        }
    }

    void initSquare()
    {
        total_points = 4 * 2;
        coordinates = initCoordinateArray();

        double _coordinates[] = {0, 0, 0, 1, 1, 1, 1, 0};
        addPointsToCoordinateArray(_coordinates);
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
            total_points = _sides * 2;
            coordinates = initCoordinateArray();
            addPointsToCoordinateArray(_coordinates);
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
        deleteCoordinateArray();
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