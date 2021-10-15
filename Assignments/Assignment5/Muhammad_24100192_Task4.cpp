#include <iostream>

using namespace std;

int getLength(char *string)
{
    int length = 0;
    while (string[length] != '\0')
    {
        length++;
    }
    return length;
}

int main()
{
    int str_size = 10000;
    char string[str_size];

    cout << "Enter string (Max Size: " << str_size << ") >> ";
    cin.get(string, str_size);

    cout << "Size of string is " << getLength(string) << endl;

    return 0;
}