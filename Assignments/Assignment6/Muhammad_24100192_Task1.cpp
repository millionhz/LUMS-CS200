#include <iostream>

using namespace std;

struct MyTime
{
    int hour;
    int minute;
    int second;
    bool is_pm;

    void operator=(const MyTime &time)
    {
        hour = time.hour;
        minute = time.minute;
        second = time.second;
        is_pm = time.is_pm;
    }

    friend ostream &operator<<(ostream &, const MyTime &);

    friend istream &operator>>(istream &, MyTime &);
};

ostream &operator<<(ostream &os, const MyTime &time)
{
    os << time.hour << ":" << time.minute << ":" << time.second << " ";
    time.is_pm ? os << "PM" : os << "AM";
    os << endl;

    return os;
}

istream &operator>>(istream &is, MyTime &time)
{
    do
    {
        cout << "Enter hours >> ";
        is >> time.hour;
    } while (time.hour < 1 || time.hour > 12);

    do
    {
        cout << "Enter minutes >> ";
        is >> time.minute;
    } while (time.minute < 0 || time.minute > 59);

    do
    {
        cout << "Enter seconds >> ";
        is >> time.second;
    } while (time.second < 0 || time.second > 59);

    int is_pm_int;
    do
    {
        cout << "Enter 1 for pm | 0 for am >> ";
        is >> is_pm_int;
    } while (is_pm_int < 0 || is_pm_int > 1);
    time.is_pm = static_cast<bool>(is_pm_int);

    return is;
}

int main()
{
    MyTime time;

    cin >> time;

    MyTime time2;
    time2 = time;

    cout << time;
    cout << time2;

    return 0;
}