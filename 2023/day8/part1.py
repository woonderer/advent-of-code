import os
with open(os.path.dirname(__file__) + "\\input.in") as file:
    f = file.read().strip().split('\n')

moves, g = f[0], dict()
for line in f[2:]:
    a, b = line.split(" = ")
    b = b[1:-1].split(", ")
    g[a] = b

ans, idx, cur = 0, 0, "AAA"
while cur != "ZZZ":
    ans += 1
    cur = g[cur][0 if moves[idx] == 'L' else 1]
    idx = (idx + 1) % len(moves)
print(ans)
