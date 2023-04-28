from samyok import *

with open("input", "r") as file:
    inp = file.read()
    inp = inp.splitlines()

ans = 0
cur = 0
line = inp[0]

for i in rl(line):
    if len(set(line[i:i + 14])) == 14:
        ans = i + 14
        break

submit(2022, 6, 2, ans)
