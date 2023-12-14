import os
with open(os.path.dirname(__file__) + "/input.in") as file:
    f = [list(line) for line in file.read().strip().split('\n')]

cycle, states = set(), []

def hash(T):
    ans = ""
    for line in f:
        ans += ''.join(line)
    return ans

def outhash(s, n, m):
    ans, idx = [['' for _ in range(m)] for _ in range(n)], 0
    for i in range(n):
        for j in range(m):
            ans[i][j] = s[idx]
            idx += 1
    return ans

while hash(f) not in cycle:
    cycle.add(hash(f))
    states.append(hash(f))

    # North
    for j in range(len(f[0])):
        pdl = -1
        for i in range(len(f)):
            if f[i][j] == '#':
                pdl = i
            elif f[i][j] == 'O':
                f[pdl + 1][j], f[i][j] = f[i][j], f[pdl + 1][j]
                pdl += 1
        
    # West
    for i in range(len(f)):
        pdl = -1
        for j in range(len(f[0])):
            if f[i][j] == '#':
                pdl = j
            elif f[i][j] == 'O':
                f[i][pdl + 1], f[i][j] = f[i][j], f[i][pdl + 1]
                pdl += 1

    # South
    for j in range(len(f[0])):
        pdl = len(f)
        for i in range(len(f) - 1, -1, -1):
            if f[i][j] == '#':
                pdl = i
            elif f[i][j] == 'O':
                f[pdl - 1][j], f[i][j] = f[i][j], f[pdl - 1][j]
                pdl -= 1

    # East
    for i in range(len(f)):
        pdl = len(f[0])
        for j in range(len(f[0]) - 1, -1, -1):
            if f[i][j] == '#':
                pdl = j
            elif f[i][j] == 'O':
                f[i][pdl - 1], f[i][j] = f[i][j], f[i][pdl - 1]
                pdl -= 1
    
start = -1
for i, state in enumerate(states):
    if hash(f) == state:
        start = i
        break

idx = start + (1000000000 - start) % (len(cycle) - start) 
f = outhash(states[idx], len(f), len(f[0]))

ans = 0
for i in range(len(f)):
    for j in range(len(f[0])):
        if f[i][j] == 'O': ans += len(f) - i
print(ans)