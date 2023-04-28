from samyok import *

with open("input", "r") as file:
    inp = file.read().strip()
    inp = inp.splitlines()
    inp = lcoerce([str, int], inp)

ans = 0

x = y = 0
aim = 0
for [d, amt] in inp:
    if d[0] == "f":
        x += amt
        y += aim * amt
    elif d[0] == "u": aim -= amt
    else: aim += amt

print(x * y)
