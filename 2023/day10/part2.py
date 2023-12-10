import os
with open(os.path.dirname(__file__) + "\\input.in") as file:
    f = file.read().strip().split('\n')

for i in range(len(f)):
    for j in range(len(f[i])):
        if f[i][j] == 'S':
            start = (i, j)
            break

q, vis = [(start[0], start[1])], set()
while len(q):
    y, x = q.pop(0)
    if (y, x) in vis: continue
    vis.add((y, x))

    if f[y][x] in ('S', '|', '7', 'F') and y + 1 < len(f) and (y + 1, x) not in vis and f[y + 1][x] in ('|', 'L', 'J'): q.append((y + 1, x))
    if f[y][x] in ('S', '|', 'L', 'J') and y - 1 >= 0 and (y - 1, x) not in vis and f[y - 1][x] in ('|', '7', 'F'): q.append((y - 1, x))
    if f[y][x] in ('S', '-', 'L', 'F') and x + 1 < len(f[0]) and (y, x + 1) not in vis and f[y][x + 1] in ('-', '7', 'J'): q.append((y, x + 1))
    if f[y][x] in ('S', '-', '7', 'J') and x - 1 >= 0 and (y, x - 1) not in vis and f[y][x - 1] in ('-', 'L', 'F'): q.append((y, x - 1))

dp = [[0 for _ in range(len(f[0]))] for _ in range(len(f))]
for i in range(len(f)):
    for j in range(len(f[0])):
        if j: dp[i][j] = dp[i][j - 1]
        if f[i][j] in ('|', 'L', 'J') and (i, j) in vis: dp[i][j] += 1

print(sum([(i, j) not in vis and dp[i][j] % 2 == 1 for j in range(len(f[0])) for i in range(len(f))]))