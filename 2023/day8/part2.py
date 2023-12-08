import os, collections, math
with open(os.path.dirname(__file__) + "\\input.in") as file:
    f = file.read().strip().split('\n')

moves, g, cur = f[0], dict(), []
for line in f[2:]:
    a, b = line.split(" = ")
    b = b[1:-1].split(", ")
    if a.endswith('A'): cur.append(a)
    g[a] = b

tab = []
for s in cur:
    xd, idx, cnt = s, 0, 0
    while not xd.endswith('Z'):
        cnt += 1
        xd = g[xd][0 if moves[idx] == 'L' else 1]
        idx = (idx + 1) % len(moves)
    tab.append(cnt)

lcm = math.lcm(tab[0], tab[1])
for i in range(2, len(tab)): 
    lcm = math.lcm(lcm, tab[i]) 
print(lcm)