from samyok import *

with open("input", "r") as file:
    inp = file.read().strip()
    inp = inp.splitlines()

ans = 0
cur = x = y = z = 0

scores = {"X": 0, "Y": 3, "Z": 6}
pick = {
    # lose draw win
    "A": ["Z", "X", "Y"],
    "B": ["X", "Y", "Z"],
    "C": ["Y", "Z", "X"],
}
points = {"X": 1, "Y": 2, "Z": 3}
for i in range(len(inp)):
    [you, me] = coerce([str, str], inp[i])
    ans += scores[me]
    ans += points[pick[you][scores[me]//3]]
    print(you, me, ans)

print(ans)

submit(2022, 2, 2, ans)
