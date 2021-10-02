#include <iostream>
#include <math.h>

using namespace std;

class Polygon
{
private:
    double **coordinates;
    int sides;

    double distance(double *point1, double *point2)
    {
        // 0 = x
        // 1 = y
        return sqrt(((point1[0] - point2[0]) * (point1[0] - point2[0])) + ((point1[1] - point2[1]) * (point1[1] - point2[1])));
    }

public:
    Polygon()
    {
        sides = 4;
        coordinates = new double *[sides];

        for (int i = 0; i < 4; i++)
        {
            coordinates[i] = new double[2];
        }

        coordinates[0][0] = 0;
        coordinates[0][1] = 0;

        coordinates[1][0] = 0;
        coordinates[1][1] = 1;

        coordinates[2][0] = 1;
        coordinates[2][1] = 1;

        coordinates[3][0] = 1;
        coordinates[3][1] = 0;
    }

    ~Polygon()
    {
        for (int i = 0; i < sides; i++)
        {
            delete[] coordinates[i];
        }
        delete[] coordinates;
    }

    double perimeter()
    {
        int perimeter = 0;
        for (int i = 0; i < sides - 1; i++)
        {
            perimeter += distance(coordinates[i], coordinates[i + 1]);
        }
        perimeter += distance(coordinates[0], coordinates[sides - 1]);

        return perimeter;
    }
};

int main()
{
    Polygon square;

    cout << square.perimeter() << endl;
    return 0;
}