from functools import cmp_to_key
from itertools import zip_longest

from samyok import *

with open("input", "r") as file:
    ln = file.read()
    lines = ln.splitlines()

ans = 0


def compare(a, b):
    if a is None:
        return -1

    if b is None:
        return 1

    if type(a) == type(b) == int:
        if a < b:
            return -1
        elif a > b:
            return 1

    if type(a) == int and type(b) == list:
        return compare([a], b)

    if type(a) == list and type(b) == int:
        return compare(a, [b])

    if type(a) == type(b) == list:
        for a, b in zip_longest(a, b):
            if compare(a, b) == 0:
                continue
            return compare(a, b)

    return 0


for i in range(0, len(lines), 3):
    first = lines[i]
    second = lines[i + 1]

    # print(first, second, compare(eval(first), eval(second)))

    if compare(eval(first), eval(second)) == -1:
        ans += i // 3 + 1

# part 1:
submit(2022, 13, 1, ans)

# part 2:
y = [[[2]], [[6]]]
x = sorted(y + list(map(eval, filter(lambda line: line != '', lines))), key=cmp_to_key(compare))
ans = (1 + x.index([[2]])) * (1 + x.index([[6]]))
submit(2022, 13, 2, ans)
