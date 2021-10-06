#include <iostream>
#include <iomanip>

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

    int *initColumn(int column_length, int *column_data)
    {
        int *column = new int[column_length];

        for (int i = 0; i < column_length; i++)
        {
            column[i] = column_data[i];
        }
        return column;
    }

    void deleteData()
    {
        for (int i = 0; i < num_of_columns; i++)
        {
            delete data[i];
        }
        delete[] data;
    }

    void deleteHeaders()
    {
        for (int i = 0; i < num_of_columns; i++)
        {
            delete headers[i];
        }
        delete[] headers;
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
            data[i] = initColumn(columns_lengths[i], _data[i]);
        }
    }

    ~Table()
    {
        delete[] columns_lengths;

        deleteHeaders();

        deleteData();
    }

    void changeColumnData(int column_number, int *arr, int new_column_length)
    {
        if (column_number > num_of_columns - 1)
        {
            return;
        }

        columns_lengths[column_number] = new_column_length;

        delete[] data[column_number];
        data[column_number] = initColumn(columns_lengths[column_number], arr);
    }

    void printTable()
    {
        for (int i = 0; i < num_of_columns; i++)
        {
            cout << left << setw(15) << headers[i];
        }
        cout << endl;

        int max_rows = columns_lengths[0];
        for (int i = 1; i < num_of_columns; i++)
        {
            if (max_rows < columns_lengths[i])
            {
                max_rows = columns_lengths[i];
            }
        }

        for (int i = 0; i < max_rows; i++)
        {
            for (int j = 0; j < num_of_columns; j++)
            {
                if (i < columns_lengths[j])
                {
                    cout << left << setw(15) << data[j][i];
                }
                else
                {
                    cout << setw(15) << " ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main()
{
    const char *headers[] = {"Calculus", "C++", "LA", "Databases"};
    int column_lengths[] = {1, 3, 2, 3};
    int **data = new int *[4];
    for (int i = 0; i < 4; i++)
        data[i] = new int[3];

    data[0][0] = 50;
    data[1][0] = 100;
    data[1][1] = 87;
    data[1][2] = 54;
    data[2][0] = 10;
    data[2][1] = 50;
    data[3][0] = 54;
    data[3][1] = 78;
    data[3][2] = 54;

    Table t(4, (int *)column_lengths, data, (char **)headers);
    t.printTable();
    return 0;
}