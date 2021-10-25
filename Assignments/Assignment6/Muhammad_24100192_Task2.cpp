#include <iostream>

using namespace std;

class MyTime
{
private:
    int hour;
    int minute;
    int second;
    bool is_pm;

    void setValues(int hour, int minute, int second, bool is_pm)
    {
        this->hour = hour;
        this->minute = minute;
        this->second = second;
        this->is_pm = is_pm;
    }

public:
    MyTime()
    {
        setValues(0, 0, 0, 0);
    }

    MyTime(int hour, int minute, int second, bool is_pm)
    {
        setValues(hour, minute, second, is_pm);
    }

    MyTime(const MyTime &time)
    {
        *this = time;
    }

    void operator=(const MyTime &time)
    {
        setValues(time.hour, time.minute, time.second, time.is_pm);
    }

    friend ostream &operator<<(ostream &, MyTime &);

    friend istream &operator>>(istream &, MyTime &);
};

ostream &operator<<(ostream &os, MyTime &time)
{
    cout << time.hour << ":" << time.minute << ":" << time.second << " ";
    time.is_pm ? cout << "PM" : cout << "AM";
    cout << endl;

    return os;
}

istream &operator>>(istream &is, MyTime &time)
{
    do
    {
        cout << "Enter hours >> ";
        cin >> time.hour;
    } while (time.hour < 0 || time.hour > 12);

    do
    {
        cout << "Enter minutes >> ";
        cin >> time.minute;
    } while (time.minute < 0 || time.minute > 59);

    do
    {
        cout << "Enter seconds >> ";
        cin >> time.second;
    } while (time.second < 0 || time.second > 59);

    int is_pm_int;
    do
    {
        cout << "Enter 1 for pm | 0 for am >> ";
        cin >> is_pm_int;
    } while (is_pm_int < 0 || is_pm_int > 1);
    time.is_pm = static_cast<bool>(is_pm_int);

    return is;
}

int main()
{
    MyTime time(12, 23, 45, 1);

    //cin >> time;

    MyTime time2;
    cout << time2;

    time2 = time;

    cout << time;
    cout << time2;

    return 0;
}