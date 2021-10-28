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
        setHour(hour);
        setMinute(minute);
        setSecond(second);
        setIsPm(is_pm);
    }

public:
    MyTime()
    {
        setValues(12, 0, 0, 0);
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

    int getHour()
    {
        return hour;
    }

    int getMinute()
    {
        return minute;
    }

    int getSecond()
    {
        return second;
    }

    bool getIsPm()
    {
        return is_pm;
    }

    void setHour(int hour)
    {
        if (hour >= 1 && hour <= 12)
        {
            this->hour = hour;
        }
        else
        {
            this->hour = 12;
        }
    }

    void setMinute(int minute)
    {
        if (minute >= 0 && minute <= 59)
        {
            this->minute = minute;
        }
        else
        {
            this->minute = 0;
        }
    }

    void setSecond(int second)
    {
        if (second >= 0 && second <= 59)
        {
            this->second = second;
        }
        else
        {
            this->second = 0;
        }
    }

    void setIsPm(bool is_pm)
    {
        this->is_pm = is_pm;
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
    MyTime time(12, 23, 45, 1);

    //cin >> time;

    MyTime time2;
    cout << time2;

    time2 = time;

    cout << time;
    cout << time2;

    return 0;
}