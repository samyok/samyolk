from collections import defaultdict
from samyok import *

with open("input", "r") as file:
    ln = file.read()
    lines = ln.splitlines()

ans = 0
cur_dir = []
dirs = set()
sizes = defaultdict(int)

for i, line in enumerate(lines):
    cmd = line.split(" ")
    if line.startswith("$ cd "):
        if cmd[2] == '..':
            cur_dir.pop()
        else:
            cur_dir.append(cmd[2])
        dirs.add("/".join(cur_dir) + "/")
    elif not line.startswith("$") and not line.startswith("dir"):
        sizes['/'.join(cur_dir) + "/" + cmd[1]] += int(cmd[0])

total_sizes = defaultdict(int)
for d in dirs:
    total_sizes[d] = sum(sizes[k] for k in sizes if k.startswith(d))
    if total_sizes[d] <= 100000:
        ans += total_sizes[d]

unused = 70000000 - total_sizes["//"]
need_to_delete = 30000000 - unused
to_delete = sorted([(v, k) for k, v in total_sizes.items() if total_sizes[k] >= need_to_delete])

# submit(2022, 7, 1, ans)
submit(2022, 7, 2, to_delete[0][0])
