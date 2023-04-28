from samyok import *

with open("input", "r") as file:
    ln = file.read()
    lines = ln.splitlines()

ans = 0


# lines are a forest of 0-9 height of trees
def how_far_we_can_see_up(r, c, h):
    for i in range(1, r + 1):
        if lines[r - i][c] >= h:
            return i
    return r


def how_far_we_can_see_down(r, c, h):
    for i in range(1, len(lines) - r):
        if lines[r + i][c] >= h:
            return i
    return len(lines) - r - 1


def how_far_we_can_see_left(r, c, h):
    for i in range(1, c + 1):
        if lines[r][c - i] >= h:
            return i
    return c


def how_far_we_can_see_right(r, c, h):
    for i in range(1, len(lines[0]) - c):
        if lines[r][c + i] >= h:
            return i
    return len(lines[0]) - c - 1


for r, line in enumerate(lines):
    for c, current_height in enumerate(line):
        ans = max(ans, how_far_we_can_see_up(r, c, current_height) * how_far_we_can_see_down(r, c,
                                                                                    current_height) * how_far_we_can_see_left(
                  r, c, current_height) * how_far_we_can_see_right(r, c, current_height))

# SUBMIT BELOW IN THE FORM OF submit({year}, {day}, {part}, {answer})
# For example, submit(2022, 3, 2, ans)
submit(2022, 8, 2, ans)
