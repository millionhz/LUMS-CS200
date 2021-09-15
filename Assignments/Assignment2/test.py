import datetime
from subprocess import run

start = datetime.datetime(1900, 12, 31)
x = datetime.datetime(2001, 1, 1)

z = x.year

while x != datetime.datetime(2022, 12, 31):
    command = f"Hamza_24100192.exe {x.day} {x.month} {x.year}"
    c = int(run(command, capture_output=True).stdout.decode("utf-8")[:-2])
    p = x - start
    if (c != p.days):
        print(x)
        print(c)
        print(p)
        break

    if x.year != z:
        print(x.year)
        z = x.year

    x = x + datetime.timedelta(days=1)
