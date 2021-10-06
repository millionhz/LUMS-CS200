#include <iostream>

using namespace std;

class Table
{
private:
    int num_of_columns;
    int *columns_lengths; //An array to store lengths of each of the column
    char **headers;       //an array of character strings
    int **data;           //A two-dimensional integer array, which stores data for each of the columns (for simplicity, we assume the data is of type integer)

    int getLength(char *s)
    {
        int i = 0;
        while (s[i] != '\0')
        {
            i++;
        }
        return i;
    }

public:
    Table()
    {
        num_of_columns = 0;
        columns_lengths = nullptr;
        headers = nullptr;
        data = nullptr;
    }

    Table(int _num_of_columns, int *_columns_lengths, int **_data, char **_headers)
    {
        num_of_columns = _num_of_columns;

        columns_lengths = new int[num_of_columns];
        for (int i = 0; i < num_of_columns; i++)
        {
            columns_lengths[i] = _columns_lengths[i];
        }

        headers = new char *[num_of_columns];
        for (int i = 0; i < num_of_columns; i++)
        {
            int len = getLength(_headers[i]);
            headers[i] = new char[len + 1];
            for (int j = 0; j < len; j++)
            {
                headers[i][j] = _headers[i][j];
            }
            headers[i][len] = '\0';
        }

        data = new int *[num_of_columns];
        for (int i = 0; i < num_of_columns; i++)
        {
            data[i] = new int[columns_lengths[i]];
        }

        for (int i = 0; i < num_of_columns; i++)
        {
            for (int j = 0; j < columns_lengths[i]; j++)
            {
                data[i][j] = 0;
            }
        }
    }

    ~Table()
    {
        delete[] columns_lengths;

        for (int i = 0; i < num_of_columns; i++)
        {
            delete[] headers[i];
            delete[] data[i];
        }
        delete[] headers;
        delete[] data;
    }

    void printTable()
    {
        for (int i = 0; i < num_of_columns; i++)
        {
            cout << headers[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    const char *headers[] = {"Calculus", "C++", "LA", "Databases"};
    int column_lengths[] = {1, 3, 2, 3};
    int data[4][4] = {
        {50, 0, 0},
        {100, 87, 54},
        {10, 50, 0},
        {54, 78, 54},
    };

    Table t(4, (int *)column_lengths, (int **)data, (char **)headers);
    t.printTable();
    return 0;
}