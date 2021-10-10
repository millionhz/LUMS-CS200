#include <iostream>

using namespace std;

void sepAndPrint(char *string)
{
    int i = 0;
    while (string[i] != '\0')
    {
        if (string[i] != ';')
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
}

int main()
{
    int str_size = 10000;
    char string[str_size];

    cout << "Enter string (Max Size: " << str_size << ") >> ";
    cin.get(string, str_size);

    sepAndPrint(string);
    return 0;
}