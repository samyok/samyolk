from samyok import *

with open("input", "r") as file:
    inp = file.read().strip()
    inp = inp.splitlines()
    inp = list(map(int, inp))

cur = prev = sum(inp[:3])
ans = 0
for i in range(0, len(inp) - 2):
    cur = sum(inp[i:3 + i])
    ans += cur > prev
    prev = cur

print(ans)
