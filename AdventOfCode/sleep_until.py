import datetime
import os
import sys
import time

def pad(n):
    return str(int(n)).rjust(2, "0")

def sleep_until(hour, minute):
    print("Sleeping until %d:%s" % (hour, pad(minute)))
    t = datetime.datetime.today()
    future = datetime.datetime(t.year, t.month, t.day, hour, minute)
    if future < t:
        print("Future is in the past, adding a day")
        future += datetime.timedelta(days=1)

    total_sleeping = future.timestamp() - t.timestamp()
    for i in range(int(total_sleeping)):
        print("\rWaiting for %d:%s" % ((total_sleeping - i) // 60, pad((total_sleeping - i) % 60)), end="")
        time.sleep(1)

    time.sleep(total_sleeping - int(total_sleeping))


sleep_until(11 + 12, 0)

print("\rdone               \n\n")
print("---")
print("\n")
