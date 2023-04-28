from collections import defaultdict
from samyok import *

with open("input", "r") as file:
    inp = file.read().strip()
    inp = inp.splitlines()

ans = 0
cur = 0

freq = [[0, 0] for i in rl(inp[0])]

for line in inp:
    for i in rl(line):
        freq[i][int(line[i])] += 1

s = ""
g = ""
for i in rl(freq):
    s += str(freq[i].index(max(freq[i])))
    g += str(freq[i].index(min(freq[i])))

ans = int(s, 2) * int(g, 2)

print(ans)
submit(2021, 3, 1, ans)