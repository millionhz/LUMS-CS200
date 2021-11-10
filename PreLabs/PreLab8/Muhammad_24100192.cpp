#include <iostream>
#include <iomanip>

using namespace std;

class Date
{
private:
    int year;
    int month;
    int day;

    int _default_year = 2020;
    int _default_month = 1;
    int _default_day = 1;

    int NumOfDays(int month, int year)
    {
        const int NUM_OF_DAYS[] = {
            31,
            IsLeapYear(year) ? 29 : 28,
            31,
            30,
            31,
            30,
            31,
            31,
            30,
            31,
            30,
            31,
        };

        return NUM_OF_DAYS[month - 1];
    }

    int IsLeapYear(int year)
    {
        if (year % 4)
        {
            return 0;
        }
        else if (year % 100)
        {
            return 1;
        }
        else if (year % 400)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }

    void setDay(int in_day)
    {
        if (in_day >= 1 && in_day <= NumOfDays(month, year))
        {
            day = in_day;
        }
        else
        {
            day = _default_day;
        }
    }

    void setMonth(int in_month)
    {
        if (in_month >= 1 && in_month <= 12)
        {
            month = in_month;
        }
        else
        {
            month = _default_month;
        }
    }

    void setYear(int in_year)
    {
        if (in_year > -1)
        {
            year = in_year;
        }
        else
        {
            year = _default_year;
        }
    }

protected:
public:
    Date()
    {
        setYear(_default_year);
        setMonth(_default_month);
        setDay(_default_day);
    }

    Date(int day, int month, int year)
    {
        setYear(year);
        setMonth(month);
        setDay(day);
    }

    void display()
    {
        cout << setw(2) << setfill('0') << day << "-" << setw(2) << setfill('0') << month << "-" << setw(4) << setfill('0') << year << endl;
    }
};

class Time : protected Date
{
private:
    int hour;
    int minute;
    int second;

    int _default_hour = 0;
    int _default_minute = 0;
    int _default_second = 0;

    void setHour(int in_hour)
    {
        if (in_hour >= 0 && in_hour <= 23)
        {
            hour = in_hour;
        }
        else
        {
            hour = _default_hour;
        }
    }

    void setMinute(int in_minute)
    {
        if (in_minute >= 0 && in_minute <= 59)
        {
            minute = in_minute;
        }
        else
        {
            minute = _default_minute;
        }
    }

    void setSecond(int in_second)
    {
        if (in_second >= 0 && in_second <= 59)
        {
            second = in_second;
        }
        else
        {
            second = _default_second;
        }
    }

protected:
public:
    Time()
    {
        setHour(_default_hour);
        setMinute(_default_minute);
        setSecond(_default_second);
    }

    Time(int hour, int minute, int second, int day, int month, int year)
        : Date(day, month, year)
    {
        setHour(hour);
        setMinute(minute);
        setSecond(second);
    }

    void display()
    {
        cout << setw(2) << setfill('0') << hour << "-" << setw(2) << setfill('0') << minute << " " << setw(2) << setfill('0') << second << " ";
        Date::display();
    }
};

int main()
{
    Date date(12, 12, 2021);
    date.display();

    Time time(11, 59, 45, 31, 12, 2021);
    time.display();
    return 0;
}