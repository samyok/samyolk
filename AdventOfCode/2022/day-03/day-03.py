from samyok import *

with open("input", "r") as file:
    inp = file.read().strip()
    inp = inp.splitlines()

ans = 0
cur = 0

for l in range(0, len(inp), 3):
    lines = inp[l:l + 3]
    for c in lines[0]:
        if c in lines[1] and c in lines[2]:
            if c.isupper():
                ans += ord(c) - 64 + 26
            else:
                ans += ord(c) - 96
            break
print(ans)

submit(2022, 3, 2, ans)
