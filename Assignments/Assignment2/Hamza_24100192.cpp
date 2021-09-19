#include <iostream>
using namespace std;

// Instructions
// Rename the file firstname_xxxxxxxx.cpp, where firstname is your first name and xxxxxxxx is your campuse id
// Upload it without compressing it

// Problem 1
// Write a function that takes an integer array and the size of the array
// The array is supposed to have 'N' integers in it, where N-1 integers are repeated even number of times
// and one integer is repeated odd number of times
// For example array = {1,5,5, 1,2,5,2,2,5}. 1 and 5 are repeated even number of times whereas 2 is odd number times.
// The function should find the element which is repeated odd number of times and return it.
// In the case of the example shown above, the function should return 2
int FindSingleElement(int arr[], int size)
{
    //int num = 0;
    int no_of_times = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                no_of_times++;
            }
        }

        //cout << no_of_times << endl;

        if (no_of_times % 2)
        {
            return arr[i];
        }

        no_of_times = 0;
    }
    return -1;
}

// An MxN matrix can be represented by a 1-D array of size M*N as follows:
// The elements at index 0 to N-1 corerspond to the first row of the matrix
// The elements at index N to 2*N-1 corerspond to the second row of the matrix
// so on
// The elements at index (M-1)*N to M*N corerspond to the last row of the matrix

// Problem 2
// Write a function to multiply two matrices. Save the resultant matrix in the 1-D array that
// is passed as argument to the function. If the function succeeds return 1. Or if the the matrices
// are incompatible for multiplication, return -1
int MatrixMultiply(int matrix1[], int r1, int c1, int matrix2[], int r2, int c2,
                   int resultant[], int &r3, int &c3)
{
    if (c1 != r2)
    {
        return -1;
    }

    r3 = r1;
    c3 = c2;

    for (int r = 0; r < r3; r++)
    {
        for (int c = 0; c < c3; c++)
        {
            int sum = 0;

            for (int k = 0; k < c1; k++)
            {
                sum += matrix1[(c1 * r) + k] * matrix2[(c2 * k) + c];
            }

            resultant[(c2 * r) + c] = sum;
        }
    }

    return 0;
}

// Problem 3
// Write a function to find the transpose of a matrix. Save the resultant matrix in the 1-D array that
// is passed as argument to the function. If the function succeeds return 1 otherwise return -1.
int MatrixTranspose(int matrix1[], int r1, int c1, int resultant[], int &r2, int &c2)
{

    for (int i = 0; i < r1 * c1; i++)
    {
        if (i == (r1 * c1 - 1))
        {
            resultant[r1 * c1 - 1] = matrix1[i];
        }
        else
        {
            resultant[(r1 * i) % ((r1 * c1) - 1)] = matrix1[i];
        }
    }

    r2 = c1;
    c2 = r1;
    return 0;
}

void printMatrix(int matrix[], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << matrix[(c * i) + j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char *argv[])
{
    // int arr[] = {1, 5, 5, 1, 2, 5, 2, 2, 2, 5, -1};
    // const int SIZE = sizeof(arr) / sizeof(int);
    // cout << FindSingleElement(arr, SIZE) << endl;

    // int m1[] = {5, 7, 9, 10, 2, 3, 3, 8, 8, 10, 2, 3, 3, 3, 4, 8};
    // int r1 = 4, c1 = 4;
    // cout << "Matrix 1:" << endl;
    // printMatrix(m1, r1, c1);

    // int m2[] = {3, 10, 12, 18, 12, 1, 4, 9, 9, 10, 12, 2, 3, 12, 4, 10};
    // int r2 = 4, c2 = 4;
    // cout << "Matrix 2:" << endl;
    // printMatrix(m2, r2, c2);

    // int resultant[r1 * c2] = {0};
    // int r3, c3;
    // MatrixMultiply(m1, r1, c1, m2, r2, c2, resultant, r3, c3);

    // cout << "Resultant:" << endl;
    // printMatrix(resultant, r3, c3);
    // cout << r3 << "X" << c3 << endl;

    int m1[] = {5, 7, 9, 10, 2, 3};
    int r1 = 2, c1 = 3;
    cout << "Matrix 1:" << endl;
    printMatrix(m1, r1, c1);

    int resultant[r1 * c1] = {0};
    int r3, c3;

    MatrixTranspose(m1, r1, c1, resultant, r3, c3);

    cout << "Resultant:" << endl;
    printMatrix(resultant, r3, c3);
    cout << r3 << "X" << c3 << endl;

    return 0;
}
