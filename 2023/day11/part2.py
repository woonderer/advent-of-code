import os, copy
with open(os.path.dirname(__file__) + "/input.in") as file:
    f = file.read().strip().split('\n')

row, col = [0] * len(f), [0] * len(f[0])
for i, line in enumerate(f):
    if i: row[i] = row[i - 1]
    if '#' not in line: row[i] += 1

for j in range(len(f[0])):
    if j: col[j] = col[j - 1]
    good = True
    for i in range(len(f)):
        if f[i][j] == '#':
            good = False
            break

    if good: col[j] += 1

pos = [] 
for i in range(len(f)):
    for j in range(len(f[0])):
        if f[i][j] == '#':
            pos.append((i, j))

ans = 0
for i in range(len(pos)):
    for j in range(i + 1, len(pos)):
        ans += abs(pos[i][0] - pos[j][0]) + abs(pos[i][1] - pos[j][1])
        ans += 999999 * (col[max(pos[i][1], pos[j][1])] - col[min(pos[i][1], pos[j][1])])
        ans += 999999 * (row[max(pos[i][0], pos[j][0])] - row[min(pos[i][0], pos[j][0])])
print(ans)