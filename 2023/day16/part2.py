import os
with open(os.path.dirname(__file__) + "\\input.in") as file:
    f = file.read().strip().split('\n')

def solve(start_y, start_x, vector_y, vector_x):
    ans, state = set(), set()
    q = [(start_y, start_x, vector_y, vector_x)]
    while q:
        y, x, v_y, v_x = q.pop(0)
        if (y, x, v_y, v_x) in state: continue
        state.add((y, x, v_y, v_x))
        y += v_y
        x += v_x
        if y < 0 or y >= len(f) or x < 0 or x >= len(f[0]): continue
        ans.add((y, x))

        if f[y][x] == '.': q.append((y, x, v_y, v_x))
        elif f[y][x] == '/' and v_x == 1: q.append((y, x, -1, 0))
        elif f[y][x] == '/' and v_x == -1: q.append((y, x, 1, 0))
        elif f[y][x] == '/' and v_y == 1: q.append((y, x, 0, -1))
        elif f[y][x] == '/' and v_y == -1: q.append((y, x, 0, 1))
        elif f[y][x] == '\\' and v_x == 1: q.append((y, x, 1, 0))
        elif f[y][x] == '\\' and v_x == -1: q.append((y, x, -1, 0))
        elif f[y][x] == '\\' and v_y == 1: q.append((y, x, 0, 1))
        elif f[y][x] == '\\' and v_y == -1: q.append((y, x, 0, -1))
        elif f[y][x] == '-' and v_y == 0: q.append((y, x, v_y, v_x))
        elif f[y][x] == '-': 
            q.append((y, x, 0, -1))
            q.append((y, x, 0, 1))
        elif f[y][x] == '|' and v_x == 0: q.append((y, x, v_y, v_x))
        elif f[y][x] == '|':
            q.append((y, x, -1, 0))
            q.append((y, x, 1, 0))

    return len(ans)

ans = []
for i in range(len(f)):
    ans.append(solve(i, -1, 0, 1))
    ans.append(solve(i, len(f[i]), 0, -1))

for i in range(len(f[0])):
    ans.append(solve(-1, i, 1, 0))
    ans.append(solve(len(f), i, -1, 0))

print(max(ans))