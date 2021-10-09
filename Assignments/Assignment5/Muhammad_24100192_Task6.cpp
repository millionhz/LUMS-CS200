#include <iostream>

using namespace std;

void sepAndPrint(char *string)
{
    int i = -1;
    do
    {
        i++;
        int j = i;
        while (string[j] != ';' && string[j] != '\0')
        {
            j++;
        }

        for (int k = i; k < j; k++)
        {
            cout << string[k];
        }
        cout << endl
             << endl;

        i = j;
    } while (string[i] == ';');
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