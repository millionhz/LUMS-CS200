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
    void SetString(MyString *ptr);
    bool IsEqualTo(char *ptr);
    bool IsEqualTo(MyString *ptr);

private:
    void _SetString(char *ptr);
    int _CalculateLength(char *ptr);
    bool _IsEqualTo(char *ptr);
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

bool MyString::_IsEqualTo(char *ptr)
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

void MyString::SetString(MyString *ptr)
{
    delete[] str;
    str = NULL;

    _SetString(ptr->str);
}

bool MyString::IsEqualTo(char *ptr)
{
    return _IsEqualTo(ptr);
}

bool MyString::IsEqualTo(MyString *ptr)
{
    return _IsEqualTo(ptr->str);
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

    MyString t((char *)"AAAAAAAAAAAAA");

    s.SetString(&t);
    cout << s.str << endl;

    s.SetString(str);

    cout << s.IsEqualTo(str) << endl;

    // cout << s.str << endl;
    // cout << s.GetLength() << endl;

    // cout << s.IsEqualTo(str) << endl;
    // s.SetString(str);
    // cout << s.IsEqualTo(str) << endl;

    return 0;
}