#include <iostream>

using namespace std;

class MyMatrix
{
private:
    int **matrix;
    int num_cols;
    int num_rows;

    bool operate(MyMatrix &other_matrix, int (*operation)(int, int))
    {
        if ((num_rows != other_matrix.num_rows) || (num_cols != other_matrix.num_cols))
        {
            return false;
        }

        for (int r = 0; r < num_rows; r++)
        {
            for (int c = 0; c < num_cols; c++)
            {
                matrix[r][c] = operation(matrix[r][c], other_matrix.matrix[r][c]);
            }
        }

        return true;
    }

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

    bool isEqualTo(MyMatrix &other_matrix)
    {
        if ((num_rows != other_matrix.num_rows) || (num_cols != other_matrix.num_cols))
        {
            return false;
        }

        for (int r = 0; r < num_rows; r++)
        {
            for (int c = 0; c < num_cols; c++)
            {
                if (matrix[r][c] != other_matrix.matrix[r][c])
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool Add(MyMatrix &other_matrix)
    {
        return operate(other_matrix, [](int a, int b)
                       { return a + b; });
    }

    bool Subtract(MyMatrix &other_matrix)
    {
        return operate(other_matrix, [](int a, int b)
                       { return a - b; });
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
    MyMatrix matrix1(m, 2, 2);
    matrix1.printMatrix();

    cout << endl;

    int n[] = {1, 0, 0, 1};
    MyMatrix matrix2(n, 2, 2);

    // cout << matrix1.isEqualTo(matrix2) << endl;

    matrix2.Add(matrix1);
    matrix2.printMatrix();

    cout << endl;

    matrix2.Subtract(matrix1);
    matrix2.printMatrix();

    cout << endl;

    return 0;
}