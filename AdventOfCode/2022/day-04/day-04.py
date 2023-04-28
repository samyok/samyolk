from samyok import *

with open("input", "r") as file:
    inp = file.read().strip()
    inp = inp.splitlines()

ans = 0
for i in rl(inp):
    line = inp[i]
    (a1, a2, b1, b2) = coerce(4*[int], line, r',|-')
    # fully contained either way
    # ans += (a1 <= b1 and b2 <= a2) or (b1 <= a1 and a2 <= b2)
    # partially contained
    ans += (a1 <= b1 <= a2) or (b1 <= a1 <= b2)

submit(2022, 4, 2, ans)
