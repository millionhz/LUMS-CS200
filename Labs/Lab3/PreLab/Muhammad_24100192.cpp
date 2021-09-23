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
    void SetString(char *ptr);
    bool IsEqualTo(char *ptr);

private:
    void _SetString(char *ptr);
    int _CalculateLength(char *ptr);
};

MyString::MyString()
{
    str = NULL;
    length = 0;
}

MyString::MyString(char *ptr)
{
    _SetString(ptr);
}

void MyString::_SetString(char *ptr)
{
    length = _CalculateLength(ptr);

    str = new char[length];

    for (int i = 0; i < length; i++)
    {
        *(str + i) = *(ptr + i);
    }
    *(str + length) = '\0';
}

int MyString::_CalculateLength(char *ptr)
{
    int len = 0;
    while (*(ptr + len) != '\0')
    {
        len++;
    }
    return len;
}

int MyString::GetLength()
{
    return length;
}

void MyString::SetString(char *ptr)
{
    delete[] str;
    str = NULL;

    _SetString(ptr);
}

bool MyString::IsEqualTo(char *ptr)
{
    int length_ptr = _CalculateLength(ptr);

    if (length_ptr == length)
    {
        for (int i; i < length; i++)
        {
            if (*(ptr + i) != *(str + i))
            {
                return false;
            }
        }

        return true;
    }
    else
    {
        return false;
    }
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
    s.SetString((char *)"CS200 Is Kinda");
    cout << s.str << endl;
    cout << s.GetLength() << endl;

    cout << s.IsEqualTo(str) << endl;
    s.SetString(str);
    cout << s.IsEqualTo(str) << endl;

    return 0;
}