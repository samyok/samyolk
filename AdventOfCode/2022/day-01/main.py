from samyok import *

with open("input", "r") as file:
    inp = file.read().strip()
    inp = inp.splitlines()


ans = []
cur = 0
for i in range(len(inp)):
    # each user score is seperated by an empty line
    if inp[i] == "":
        ans.append(cur)
        cur = 0
        continue
    cur += int(inp[i])

# print sum of top three scores
print(sum(sorted(ans, reverse=True)[:3]))