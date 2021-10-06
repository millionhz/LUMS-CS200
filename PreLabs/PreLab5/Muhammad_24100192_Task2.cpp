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

    void initTable(int _num_of_columns, int *_columns_lengths, int **_data, char **_headers)
    {
        num_of_columns = _num_of_columns;

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

        columns_lengths = new int[num_of_columns];
        for (int i = 0; i < num_of_columns; i++)
        {
            columns_lengths[i] = _columns_lengths[i];
        }

        data = new int *[num_of_columns];
        for (int i = 0; i < num_of_columns; i++)
        {
            data[i] = initColumn(columns_lengths[i], _data[i]);
        }
    }

    void printHeaders()
    {
        for (int i = 0; i < num_of_columns; i++)
        {
            cout << left << setw(15) << headers[i];
        }
        cout << endl;
    }

    double average(int column_number)
    {
        int sum = 0;
        for (int i = 0; i < columns_lengths[column_number]; i++)
        {
            sum += data[column_number][i];
        }

        return static_cast<double>(sum) / columns_lengths[column_number];
    }

    void deleteTable()
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
        initTable(_num_of_columns, _columns_lengths, _data, _headers);
    }

    ~Table()
    {
        deleteTable();
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

    void setData(int _num_of_columns, int *_columns_lengths, int **_data, char **_headers)
    {
        deleteTable();
        initTable(_num_of_columns, _columns_lengths, _data, _headers);
    }

    void printTable()
    {
        printHeaders();

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
    }

    void printColumn(int column_number)
    {
        cout << headers[column_number] << endl;

        for (int i = 0; i < columns_lengths[column_number]; i++)
        {
            cout << data[column_number][i] << endl;
        }
    }

    void printColumnAverage()
    {
        printHeaders();

        for (int i = 0; i < num_of_columns; i++)
        {
            cout << left << setw(15) << average(i);
        }
        cout << endl;
    }
};

int main()
{
    int num_of_columns = 0;

    cout << "Input Number of Columns >> ";
    cin >> num_of_columns;

    int *columns_lengths = new int[num_of_columns];
    for (int i = 0; i < num_of_columns; i++)
    {
        cout << "Enter Length of Column " << i + 1 << " >> ";
        cin >> columns_lengths[i];
    }

    string *_headers = new string[num_of_columns];
    string sentinel;
    getline(cin, sentinel);
    for (int i = 0; i < num_of_columns; i++)
    {
        string s;
        cout << "Enter Name of Column " << i + 1 << " >> ";
        getline(cin, _headers[i]);
    }

    //converting string headers to c-string headers
    char const **headers = new char const *[num_of_columns];
    for (int i = 0; i < num_of_columns; i++)
    {
        headers[i] = _headers[i].c_str();
    }

    int **data = new int *[num_of_columns];
    for (int i = 0; i < num_of_columns; i++)
    {
        data[i] = new int[columns_lengths[i]];
    }

    for (int i = 0; i < num_of_columns; i++)
    {
        for (int j = 0; j < columns_lengths[i]; j++)
        {
            cout << "Enter Value of Row " << j + 1 << " of Column " << headers[i] << " >> ";
            cin >> data[i][j];
        }
    }

    Table my_table(num_of_columns, columns_lengths, data, (char **)headers);

    my_table.printTable();
    my_table.printColumnAverage();

    while (1)
    {
        int column_number;
        do
        {
            cout << "Enter Column Number To Print (1 : first column ...) >> ";
            cin >> column_number;
        } while (column_number < 1 || column_number > num_of_columns);

        my_table.printColumn(column_number - 1);
    }

    return 0;
}