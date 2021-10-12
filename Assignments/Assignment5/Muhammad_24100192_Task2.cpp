#include <iostream>

using namespace std;

void calc(char *string, int *pNumAlphabetsLower, int *pNumAlphabetsUpper, int *pNumNumbers, int *pNumSpecialChars)
{
    int i = 0;
    while (string[i] != '\0')
    {
        char current_char = string[i];
        if (current_char >= 97 && current_char <= 122)
        {
            (*pNumAlphabetsLower)++;
        }
        else if (current_char >= 65 && current_char <= 90)
        {
            (*pNumAlphabetsUpper)++;
        }
        else if (current_char >= 48 && current_char <= 57)
        {
            (*pNumNumbers)++;
        }
        else
        {
            (*pNumSpecialChars)++;
        }

        i++;
    }
}

int main()
{
    int str_size = 10000;
    char s[str_size];

    cout << "Enter string (Max Size: " << str_size << ") >> ";
    cin.get(s, str_size);

    int pNumAlphabetsLower = 0;
    int pNumAlphabetsUpper = 0;
    int pNumNumbers = 0;
    int pNumSpecialChars = 0;

    calc(s, &pNumAlphabetsLower, &pNumAlphabetsUpper, &pNumNumbers, &pNumSpecialChars);

    cout << "Lower Case Characters: " << pNumAlphabetsLower << endl;
    cout << "Upper Case Characters: " << pNumAlphabetsUpper << endl;
    cout << "Numbers: " << pNumNumbers << endl;
    cout << "Special Characters: " << pNumSpecialChars << endl;

    return 0;
}