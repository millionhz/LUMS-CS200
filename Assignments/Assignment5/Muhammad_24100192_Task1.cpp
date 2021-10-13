#include <iostream>

using namespace std;

class MyMatrix
{
private:
    int **matrix;
    int num_cols;
    int num_rows;

    bool operate(const MyMatrix &other_matrix, int (*operation)(int, int))
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

    int **initMatrix(int in_num_rows, int in_num_cols)
    {
        int **out_matrix = new int *[in_num_rows];
        for (int i = 0; i < in_num_rows; i++)
        {
            out_matrix[i] = new int[in_num_cols];
        }

        return out_matrix;
    }

    int **deleteMatrix(int **in_matrix, int in_num_rows)
    {
        for (int i = 0; i < in_num_rows; i++)
        {
            delete[] in_matrix[i];
        }
        delete[] in_matrix;

        return nullptr;
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

        matrix = initMatrix(num_rows, num_cols);

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

    MyMatrix(const MyMatrix &in_matrix)
    {
        num_rows = in_matrix.num_rows;
        num_cols = in_matrix.num_cols;

        matrix = initMatrix(num_rows, num_cols);

        for (int r = 0; r < num_rows; r++)
        {
            for (int c = 0; c < num_cols; c++)
            {
                matrix[r][c] = in_matrix.matrix[r][c];
            }
        }
    }

    ~MyMatrix()
    {
        matrix = deleteMatrix(matrix, num_rows);
    }

    bool isEqualTo(const MyMatrix &other_matrix)
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

    bool Add(const MyMatrix &other_matrix)
    {
        return operate(other_matrix, [](int a, int b)
                       { return a + b; });
    }

    bool Subtract(const MyMatrix &other_matrix)
    {
        return operate(other_matrix, [](int a, int b)
                       { return a - b; });
    }

    bool Multiply(const MyMatrix &other_matrix)
    {
        if (num_cols != other_matrix.num_rows)
        {
            return false;
        }

        int **resultant = initMatrix(num_rows, other_matrix.num_cols);

        for (int r = 0; r < num_rows; r++)
        {
            for (int c = 0; c < other_matrix.num_cols; c++)
            {
                int sum = 0;

                for (int k = 0; k < num_cols; k++)
                {
                    sum += matrix[r][k] * other_matrix.matrix[k][c];
                }

                resultant[r][c] = sum;
            }
        }

        matrix = deleteMatrix(matrix, num_rows);
        num_cols = other_matrix.num_cols;
        matrix = resultant;

        return true;
    }

    void Transpose()
    {
        if (num_rows < 1 || num_cols < 1)
        {
            return;
        }

        int **resultant = initMatrix(num_cols, num_rows);

        for (int r = 0; r < num_rows; r++)
        {
            for (int c = 0; c < num_cols; c++)
            {
                resultant[c][r] = matrix[r][c];
            }
        }

        matrix = deleteMatrix(matrix, num_rows);
        matrix = resultant;

        int temp = num_cols;
        num_cols = num_rows;
        num_rows = temp;
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
    int m[] = {1, 0, 0, 1};
    MyMatrix matrix1(m, 2, 2);
    matrix1.printMatrix();
    cout << endl;

    int n[] = {3, 0, 3, 1, 2, 4};
    MyMatrix matrix2(n, 2, 3);
    matrix2.printMatrix();
    cout << endl;

    matrix2.Transpose();
    matrix2.printMatrix();

    MyMatrix matrix3 = matrix1;

    cout << endl;
    matrix3.printMatrix();

    // matrix1.Multiply(matrix2);
    // matrix1.printMatrix();

    return 0;
}