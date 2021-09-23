import datetime
from subprocess import run
from multiprocessing import Process
from sys import exit

filename = "Hamza_24100192"

# compile
#run(f"g++ {filename}.cpp -o {filename}.exe", stdout=True)


def test(year_start, year_end):
    z = 0  # used for logging
    start = datetime.datetime(1900, 12, 31)
    x = datetime.datetime(year_start, 1, 1)

    while x != datetime.datetime(year_end, 12, 31):
        command = f"{filename}.exe {x.day} {x.month} {x.year}"
        c = int(run(command, capture_output=True).stdout.decode("utf-8")[:-2])
        p = x - start
        if (c != p.days):
            print(x)
            print(c)
            print(p)
            break

        if x.year != z:
            print(f"Checking {x.year}...")
            z = x.year

        x = x + datetime.timedelta(days=1)


def get_years(end, step):
    years = []
    start = 1900

    while start != end:
        years.append((start+1, start+step))
        start = years[-1][1]

    return years


if __name__ == "__main__":

    years = get_years(2020, 30)
    process_count = len(years)
    process = []

    # print(process_count)

    # exit()

    for i in range(process_count):
        process.append(
            Process(target=test, args=years[i])
        )
        print(process[i].name)

    for i in range(process_count):
        process[i].start()

    for i in range(process_count):
        process[i].join()
