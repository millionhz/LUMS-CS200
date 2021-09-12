import calendar
from subprocess import run


def get_month(month):
    if month == "January":
        return 1
    elif month == "February":
        return 2
    elif month == "March":
        return 3
    elif month == "April":
        return 4
    elif month == "May":
        return 5
    elif month == "June":
        return 6
    elif month == "July":
        return 7
    elif month == "August":
        return 8
    elif month == "September":
        return 9
    elif month == "October":
        return 10
    elif month == "November":
        return 11
    elif month == "December":
        return 12
    else:
        return -1


def get_day(day):
    if day == "Monday":
        return 0
    elif day == "Tuesday":
        return 1
    elif day == "Wednesday":
        return 2
    elif day == "Thursday":
        return 3
    elif day == "Friday":
        return 4
    elif day == "Saturday":
        return 5
    elif day == "Sunday":
        return 6
    else:
        return -1


def get_output(firstday, leap, date, month):
    command = ["Hamza_24100192.exe", str(
        firstday), str(leap), str(date), str(month)]
    output = run(command, capture_output=True)
    output = output.stdout.decode("utf-8").split(" ")
    return {
        "Month": get_month(output[0]),
        "Date": int(output[1]),
        "Day": get_day(output[-1][0:-2])
    }


for y in range(2000, 2022):
    for m in range(1, 13):
        for _year, _month, date, day in calendar.Calendar().itermonthdays4(y, m):

            leap = int(calendar.isleap(y))
            first_day = calendar.weekday(y, 1, 1) + 1
            if first_day == 7:
                first_day = 0

            if _month == m:
                output = get_output(first_day, leap, date, m)
                # assert(m == _month == output["Month"])
                if day != output["Day"]:
                    print(f"Command: {first_day} {leap} {date} {m}")
                    print(f"Year: {y}")

                    print("ERROR")

    print(f"Year {y} PASSED...")

# 0 is Monday (the default), 6 is Sunday in python calendar
