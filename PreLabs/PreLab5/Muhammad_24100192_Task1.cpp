#include <iostream>

using namespace std;

char ConvertToLowerCase(char c)
{
    if (c <= 90 && c >= 65)
    {
        return c + 32;
    }
    else
    {
        return c;
    }
}

char ConvertToUpperCase(char c)
{
    if (c <= 122 && c >= 97)
    {
        return c - 32;
    }
    else
    {
        return c;
    }
}

string ConvertString(string s, char (*func)(char))
{
    int i = 0;
    while (s[i] != '\0')
    {
        s[i] = func(s[i]);
        i++;
    }

    return s;
}

int main()
{
    char (*functptr[])(char) = {ConvertToLowerCase, ConvertToUpperCase};
    string s = "";
    int option = 0;

    cout << "Input string >> ";
    getline(cin, s);

    do
    {
        cout << "Enter option [0 - ConvertToLowerCase | 1 - ConvertToUpperCase] >> ";
        cin >> option;
    } while (option != 0 && option != 1);

    cout << ConvertString(s, functptr[option]) << endl;
}