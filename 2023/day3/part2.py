import os
with open(os.path.dirname(__file__) + "\\input.in") as file:
    f = file.read().split('\n')

gears = [[[1, 0] for _ in range(len(f))] for _ in range(len(f[0]))]

for i in range(len(f)):
    j = 0
    while j < len(f[i]):
        j2 = j
        if f[i][j] in '0123456789':
            cur = f[i][j2]
            while j2 < len(f[i]) - 1 and f[i][j2 + 1] in '0123456789':
                cur += f[i][j2 + 1]
                j2 += 1
            
            for y in range(i - 1, i + 2):
                for x in range(j - 1, j2 + 2):
                    if 0 <= y and y < len(f) and 0 <= x and x < len(f[y]):
                        if f[y][x] == '*':
                            gears[y][x][0] *= int(cur)
                            gears[y][x][1] += 1

        j = j2 + 1

ans = 0
for y in gears:
    for x in y:
        if x[1] == 2:
            ans += x[0]
print(ans)