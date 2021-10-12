#include <iostream>

using namespace std;

class MyMatrix
{
private:
    int **matrix;
    int num_cols;
    int num_rows;

public:
    MyMatrix()
    {
        matrix = NULL;
        num_rows = 0;
        num_cols = 0;
    }

    MyMatrix(int *in_matrix, int in_num_rows, int in_num_cols)
    {
        num_rows = in_num_rows;
        num_cols = in_num_cols;

        matrix = new int *[num_rows];
        for (int i = 0; i < num_rows; i++)
        {
            matrix[i] = new int[num_cols];
        }

        int x = 0;
        for (int r = 0; r < num_rows; r++)
        {
            for (int c = 0; c < num_cols; c++)
            {
                matrix[r][c] = in_matrix[x];
                x++;
            }
        }
    }

    MyMatrix(MyMatrix &in_matrix)
    {
        // TODO
    }

    ~MyMatrix()
    {
        for (int i = 0; i < num_rows; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    void printMatrix()
    {
        for (int r = 0; r < num_rows; r++)
        {
            for (int c = 0; c < num_cols; c++)
            {
                cout << matrix[r][c] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int m[] = {1, 1, 1, 1};
    MyMatrix matrix(m, 2, 2);
    matrix.printMatrix();

    MyMatrix m2(matrix);
    m2.printMatrix();

    return 0;
}