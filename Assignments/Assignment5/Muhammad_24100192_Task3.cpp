#include <iostream>
using namespace std;

int getlength(char *string)
{
    int length = 0;
    while (string[length] != '\0')
    {
        length++;
    }
    return length;
}

bool compare(char *string1, char *string2)
{

    int string1_len = getlength(string1);
    int string2_len = getlength(string2);

    if (string1_len == string2_len)
    {
        for (int i = 0; i < getlength(string1); i++)
        {
            if (string1[i] != string2[i])
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
    return true;
}

int main()
{
    int str_size = 10000;
    char s1[str_size];
    char s2[str_size];

    cout << "Enter string 1 (Max Size: " << str_size << ") >> ";
    cin.get(s1, str_size);

    cin.ignore(1000, '\n');

    cout << "Enter string 2 (Max Size: " << str_size << ") >> ";
    cin.get(s2, str_size);

    if (compare(s1, s2))
    {
        cout << "Strings are equal" << endl;
    }
    else
    {
        cout << "Strings are not equal" << endl;
    }

    return 0;
}