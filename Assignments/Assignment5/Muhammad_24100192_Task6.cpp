#include <iostream>

using namespace std;

void sepAndPrint(char *string, char terminator)
{
    int i = 0;
    while (string[i] != '\0')
    {
        if (string[i] != terminator)
        {
            cout << string[i];
        }
        else
        {
            cout << endl
                 << endl;
        }
        i++;
    }
    cout << endl;
}

int main()
{
    int str_size = 10000;
    char string[str_size];
    char terminator;

    cout << "Enter string (Max Size: " << str_size << ") >> ";
    cin.get(string, str_size);

    cin.ignore(1000, '\n');

    cout << "Enter therminator character >> ";
    cin >> terminator;

    sepAndPrint(string, terminator);
    return 0;
}