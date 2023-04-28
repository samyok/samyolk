from samyok import *

with open("input", "r") as file:
    ln = file.read()
    lines = ln.splitlines()

snake = [[0, 0] for i in range(10)]

traveled = {(0, 0)}

for i, line in enumerate(lines):
    [c, n] = coerce([str, int], line)
    for _ in range(n):
        d = {"U": [-1, 0], "D": [1, 0], "L": [0, -1], "R": [0, 1]}[c]
        snake[0][0] += d[0]
        snake[0][1] += d[1]

        for cur, prev in zip(snake[1:], snake):
            if distance(cur, prev) > 2:
                cur[0] += 1 if prev[0] > cur[0] else -1 if prev[0] < cur[0] else 0
                cur[1] += 1 if prev[1] > cur[1] else -1 if prev[1] < cur[1] else 0

        traveled.add((snake[-1][0], snake[-1][1]))

submit(2022, 9, 2, len(traveled))
