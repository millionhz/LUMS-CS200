#include <iostream>

using namespace std;

class TimeStamp
{
public:
    int date;
    int month;
    int year;
    int hour;
    int minute;
    int second;

    TimeStamp();
    TimeStamp(int _date, int _month, int _year, int _hour, int _minute, int _second);
    void AddSeconds(int seconds_to_add);

private:
    void _setValues(int _date, int _month, int _year, int _hour, int _minute, int _second);
    int _numOfDays(int month, int year);
    int _isLeapYear(int year);
    void _addSecondsLimit_86400(int seconds_to_add);
};

void TimeStamp::_setValues(int _date, int _month, int _year, int _hour, int _minute, int _second)
{
    date = _date;
    month = _month;
    year = _year;
    hour = _hour;
    minute = _minute;
    second = _second;
}

int TimeStamp::_isLeapYear(int year)
{
    if (year <= 1900)
    {
        return -1;
    }
    else
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
}

int TimeStamp::_numOfDays(int month, int year)
{
    if (year <= 1900 || month < 1 || month > 12)
    {
        return -1;
    }
    else
    {
        const int NUM_OF_DAYS[] = {
            31,
            _isLeapYear(year) ? 29 : 28,
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
}
TimeStamp::TimeStamp()
{
    _setValues(1, 1, 1901, 0, 0, 0);
}

TimeStamp::TimeStamp(int _date, int _month, int _year, int _hour, int _minute, int _second)
{
    if ((_date >= 1 && _date <= _numOfDays(_month, _year)) && (_month >= 1 && _month <= 12) && (_year >= 1901) && (_hour >= 0 && _hour <= 23) && (_minute >= 0 && _minute <= 59) && (_second >= 0 && _second <= 59))
    {
        _setValues(_date, _month, _year, _hour, _minute, _second);
    }
    else
    {
        _setValues(1, 1, 1901, 0, 0, 0);
    }
}

void TimeStamp::_addSecondsLimit_86400(int left_to_add)
{
    // 86400 = 60*60*24 (number of seconds in a day)

    int *elements[] = {&second, &minute, &hour, &date, &month};
    int vals[] = {60, 60, 24, _numOfDays(month, year) + 1, 13};

    const int SIZE = 5;

    for (int i = 0; i < SIZE && left_to_add > 0; i++)
    {

        int x = (*elements[i] + left_to_add);
        *elements[i] = x % vals[i];
        left_to_add = x / vals[i];

        if (i > 2 && *elements[i] == 0)
        {
            (*elements[i])++;
        }

        // updating state of numOfDays (in a month)
        vals[3] = _numOfDays(month, year) + 1;
    }
    year += left_to_add;
}

void TimeStamp::AddSeconds(int seconds_to_add)
{
    // function works for smaller chunks, so i am adding iteratively

    int thresh = 60 * 60 * 24;
    while (seconds_to_add)
    {
        if (seconds_to_add <= thresh)
        {
            _addSecondsLimit_86400(seconds_to_add);
            return;
        }
        else
        {
            _addSecondsLimit_86400(thresh);
            seconds_to_add -= thresh;
        }
    }
    return;
}

int main()
{
    TimeStamp myTime(31, 12, 2000, 0, 0, 0);
    myTime.AddSeconds(60 * 60 * 24 * 2);
    cout << myTime.second << "-" << myTime.minute << "-" << myTime.hour << "-" << myTime.date << "-" << myTime.month << "-" << myTime.year << endl;

    return 0;
}