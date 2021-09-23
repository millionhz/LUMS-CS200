#include <iostream>

using namespace std;

class MyString
{
public:
    char *str;
    int length = 0;
    MyString();
    MyString(char *ptr);
    ~MyString();
    int GetLength();
};

MyString::MyString()
{
    str = NULL;
    length = 0;
}

MyString::MyString(char *ptr)
{
    // calculate length;
    while (*(ptr + length) != '\0')
    {
        length++;
    }

    str = new char[length];

    for (int i = 0; i < length; i++)
    {
        *(str + i) = *(ptr + i);
    }
    *(str + length) = '\0';
}

int MyString::GetLength()
{
    return length;
}

MyString::~MyString()
{
    delete[] str;
    str = NULL;
}

int main()
{
    char *str = (char *)"CS200";

    MyString s(str);
    cout << s.str << endl;
    cout << s.GetLength() << endl;

    return 0;
}