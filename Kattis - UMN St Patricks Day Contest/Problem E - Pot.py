n = int(input())
sm = 0
for i in range(n):
    a = input()
    sm += int(a[:-1]) ** int(a[-1])

print(sm)