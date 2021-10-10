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

int findString(char *string1, char *string2)
{
    int string1_len = getlength(string1);
    int string2_len = getlength(string2);

    if (string1_len >= string2_len)
    {
        for (int i = 0; i < string1_len; i++)
        {
            bool found = true;
            for (int j = 0, k = i; j < string2_len; j++, k++)
            {
                if (string1[k] != string2[j])
                {
                    found = false;
                    break;
                }
            }

            if (found)
            {
                return i;
            }
        }
    }

    return -1;
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

    int index = findString(s1, s2);

    if (index != -1)
    {
        cout << s2 << " found at index " << index << endl;
    }
    else
    {
        cout << s2 << " not found" << endl;
    }

    return 0;
}