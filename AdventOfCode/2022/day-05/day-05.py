from samyok import *

with open("input", "r") as file:
    inp = file.read()
    inp = inp.splitlines()
N = 9

piles = [""] * N
x = 0
for line in inp:
    if line == "":
        break
    for i in range(0, N):
        piles[i] += line[i * 4 + 1]
    x += 1

piles = [p.strip()[:-1] for p in piles]

for line in inp[x + 1:]:
    [n, from_pile, to_pile] = extract_ints(line)
    piles[to_pile - 1] = piles[from_pile - 1][:n] + piles[to_pile - 1]
    piles[from_pile - 1] = piles[from_pile - 1][n:]

ans = "".join([pile[0] for pile in piles])
submit(2022, 5, 2, ans)
