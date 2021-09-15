#include <iostream>
using namespace std;

// Instructions:
// Do not print anything inside the function.
// Even the invalid inputs should not be printed
// Errors should be reported by returning -1 as indicated
// We will assess the functions only for correctness. You can write
// main function to test the four functions. However, we will ignore main
// function.

// Important:
// Write all the four functions in the same file.
// Name the file as firstname_campusid.cpp
// Upload the single file without zipping it
// 10% deduction in case of not following these instructions

// Problem 1: Write a function to check if the given year is a leap year
// Should return 1 if the year is a leap year, 0 otherwise
// We will handle only years>=1901. So if year<=1900, return -1 to indicate an error
// Note: do not print anything in the function.
int IsLeapYear(int year)
{

    // if (year is not divisible by 4) then (it is a common year)
    // else if (year is not divisible by 100) then (it is a leap year)
    // else if (year is not divisible by 400) then (it is a common year)
    // else (it is a leap year)

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

// Problem 2: Return number of days in a given month. You must check for the leap year.
// Return number of days of the given month
// Return -1 in case of inavlid input. Year<=1900 in all cases should be considered invalid
int NumOfDays(int month, int year)
{
    if (year <= 1900 || month < 1 || month > 12)
    {
        return -1;
    }
    else
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
}

// Problem 3:
// Return 1 incase date is valid. Year <=1900 should be consiered invalid
// Return -1 in case date is not invalid.
int IsValidDate(int date, int month, int year)
{
    if (year <= 1900 || month < 1 || month > 12)
    {
        return -1;
    }
    else
    {
        if (date >= 1 && date <= NumOfDays(month, year))
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
}

// Problem 4: Compute number of days passed since Dec 31, 1900.
// Following are some of the example input dates and the corresponding output
// 1 1 1901. Should return 1
// 31 1 1901. should return 31
// 31 12 1901. Should return  365
// 31 12 2000. should return 36525 (how?)
// The function should return (not print) the number of days after calculating.
// Return -1 incase date is invalid
int NumOfDaysPasssed(int date, int month, int year)
{
    return -1;
}

int main(int argc, char *argv[])
{
    int year = stoi(argv[1]);
    cout << IsLeapYear(year) << endl;

    cout << endl;

    // for (int i = 1; i <= 12; i++)
    // {
    //     cout << NumOfDays(i, year) << endl;
    // }

    return 0;
}
