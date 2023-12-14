import os
with open(os.path.dirname(__file__) + "/input.in") as file:
    f = [list(line) for line in file.read().strip().split('\n')]

for j in range(len(f[0])):
    pdl = -1
    for i in range(len(f)):
        if f[i][j] == '#':
            pdl = i
        elif f[i][j] == 'O':
            f[pdl + 1][j], f[i][j] = f[i][j], f[pdl + 1][j]
            pdl += 1
    
ans = 0
for i in range(len(f)):
    for j in range(len(f[0])):
        if f[i][j] == 'O': ans += len(f) - i
print(ans)