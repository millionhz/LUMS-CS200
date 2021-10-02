#include <iostream>

using namespace std;

int main()
{

    // input number of rows
    int rows;
    cout << "Enter number of rows >> ";
    cin >> rows;

    // allocate memory for 2d array
    int **r = new int *[rows];
    int c[rows];

    // input number of columns
    for (int i = 0; i < rows; i++)
    {
        int x;
        cout << "Enter number of columns of row " << i << " >> ";
        cin >> x;
        *(c + i) = x;
    }

    // allocate memory for each row
    for (int i = 0; i < rows; i++)
    {
        *(r + i) = new int[*(c + i)];
    }

    // get values for each row
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < *(c + i); j++)
        {
            int x;
            cout << "Enter [" << i << "][" << j << "] >> ";
            cin >> x;
            *(*(r + i) + j) = x;
        }
    }

    // calculate sum of each row
    for (int i = 0; i < rows; i++)
    {
        int sum = 0;
        for (int j = 0; j < *(c + i); j++)
        {
            sum += *(*(r + i) + j);
        }
        cout << "Sum of row " << i << " >> " << sum << endl;
    }

    // deallocate memory of array
    for (int i = 0; i < rows; i++)
    {
        delete[] * (r + i);
    }
    delete[] r;
    r = nullptr;

    return 0;
}