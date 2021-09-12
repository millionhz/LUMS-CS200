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

    if (first_day < 0 || first_day > 6)
    {
        cout << "Invalid Value for first_date: " << first_day << endl;
        cout << "first_date must be between 0 and 6 (inclusive)" << endl;
        return -1;
    }

    if (leap_year < 0 || leap_year > 1)
    {
        cout << "Invalid value for lead_year: " << leap_year << endl;
        cout << "leap_year must be either 0 or 1" << endl;
        return -1;
    }

    if (month < 1 || month > 12)
    {
        cout << "Invalid value for month: " << month << endl;
        cout << "month must be between 1 and 12 (inclusive)" << endl;
        return -1;
    }

    int day_of_week = first_day;
    int total_days_from_start = 0;
    const int TOTAL_MONTHS = 12;
    string month_name = "";
    string day_name = "";
    const int NUM_OF_DAYS[TOTAL_MONTHS] = {
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

    // set month name
    switch (month)
    {
    case 1:
        month_name = "January";
        break;
    case 2:
        month_name = "February";
        break;
    case 3:
        month_name = "March";
        break;
    case 4:
        month_name = "April";
        break;
    case 5:
        month_name = "May";
        break;
    case 6:
        month_name = "June";
        break;
    case 7:
        month_name = "July";
        break;
    case 8:
        month_name = "August";
        break;
    case 9:
        month_name = "September";
        break;
    case 10:
        month_name = "October";
        break;
    case 11:
        month_name = "November";
        break;
    case 12:
        month_name = "December";
        break;
    default:
        month_name = "ERROR";
    }

    // should be done at the end as we need information about the months to print a valid help message
    if (date < 1 || date > NUM_OF_DAYS[month - 1])
    {
        cout << "Invalid value for date: " << date << endl;
        cout << "date must be between 1 and " << NUM_OF_DAYS[month - 1] << " (inclusive) for the month of " << month_name << endl;
        return -1;
    }

    for (int m = 1; m < month; m++)
    {
        total_days_from_start += NUM_OF_DAYS[m - 1];
    }
    total_days_from_start += date;

    //cout << total_days_from_start << endl;

    // -1 because we have our first week day instance as 0 not 1 but the first instance of a calendar is 1
    day_of_week = ((total_days_from_start + first_day - 1) % 7);

    switch (day_of_week)
    {
    case 0:
        day_name = "Sunday";
        break;
    case 1:
        day_name = "Monday";
        break;
    case 2:
        day_name = "Tuesday";
        break;
    case 3:
        day_name = "Wednesday";
        break;
    case 4:
        day_name = "Thursday";
        break;
    case 5:
        day_name = "Friday";
        break;
    case 6:
        day_name = "Saturday";
        break;
    default:
        day_name = "ERROR";
    }

    cout << month_name << " " << date << " is " << day_name << endl;

    /*****Your code ends here*******/

    /*****Do not change following code */
    return 0;
    /***********************************/
}
