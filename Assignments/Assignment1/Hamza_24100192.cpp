#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

/* Suppose you are given the following information */
// Integer:first_day. This is the day on Jan 1 where 0 is sunday 1 is monday and ... 6 is Saturday
// Integer: leap_year. leap_year=1 indicates that the given year is leap year and 0 indicates not a leap year
// Integer: date (between 1 to Max days of the month, both inclusive)
// Integer: month (between 1 to 12, both inclusive
/*Your task is to find the day name on the given date and print the output in the following format*/
// June 10 is Saturday
/* Valide the input values and print appropriate error messages */

/* Make sure to comply the output format. Month name should be printed instead of numerical equal of the day.
/* Also day name should be printed instread of numerical equal of the month*/

// Write your code at the specified location in the main function.
// Do not change the other code.
// Name the file as firstname_xxxxxxxx. Replace fistname with your actual first name and replace xxxxxxxx
// with your campuse id
// upload the file on LMS  without zipping it

string day_name(const int x)
{
    switch (x)
    {
    case 0:
        return "Sunday";
    case 1:
        return "Monday";
    case 2:
        return "Tuesday";
    case 3:
        return "Wednesday";
    case 4:
        return "Thursday";
    case 5:
        return "Friday";
    case 6:
        return "Saturday";
    default:
        return "ERROR";
    }
}

string month_name(const int x)
{
    switch (x)
    {
    case 1:
        return "January";
    case 2:
        return "February";
    case 3:
        return "March";
    case 4:
        return "April";
    case 5:
        return "May";
    case 6:
        return "June";
    case 7:
        return "July";
    case 8:
        return "August";
    case 9:
        return "September";
    case 10:
        return "October";
    case 11:
        return "November";
    case 12:
        return "December";
    default:
        return "ERROR";
    }
}

int main(int argc, char *argv[])
{
    /*****Do not change following code */
    int first_day = atoi(argv[1]);
    int leap_year = atoi(argv[2]);
    int date = atoi(argv[3]);
    int month = atoi(argv[4]);
    /***********************************/

    /****Your code starts here***/
    // No need to take input from the user. First four lines are for user input. So, you
    // assume that the input values are already in the variables declared in the first four lines.

    int day_of_week = first_day;

    const int TOTAL_MONTHS = 12;
    const int x[TOTAL_MONTHS] = {
        31,
        (leap_year) ? 29 : 28,
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

    for (int m = 1; m <= month || m > TOTAL_MONTHS; m++)
    {
        for (int d = 1; d <= x[m - 1]; d++)
        {

            cout << d << "-" << m << ": " << day_name(day_of_week) << endl;

            if (m == month && d == date)
                break;

            day_of_week++;
            if (day_of_week > 6)
                day_of_week = 0;
        }
    }

    cout << month_name(month) << " " << date << " is " << day_name(day_of_week) << endl;

    /*****Your code ends here*******/

    /*****Do not change following code */
    return 0;
    /***********************************/
}
