import os, collections, functools
with open(os.path.dirname(__file__) + "\\input.in") as file:
    f = [[line.split()[0], int(line.split()[1])] for line in file.read().strip().split('\n')]

def rank(m):
    if len(m) == 1: return 6
    elif len(m) == 2: return 5 if 1 in m.values() else 4
    elif len(m) == 3: return 3 if 3 in m.values() else 2
    return 1 if len(m) == 4 else 0

def cmp(p):
    m, j = collections.defaultdict(int), 0
    for c in p[0]: 
        if c != 1: m[c] += 1
        else: j += 1

    if j == 5: return 6, p[0]

    best = list(m.keys())[0]
    for x in m: 
        if m[x] > m[best]: best = x
    m[best] += j

    return rank(m), p[0]
    
def change(c):
    if c == 'A': return 14
    elif c == 'K': return 13
    elif c == 'Q': return 12
    elif c == 'J': return 1
    elif c == 'T': return 10
    return int(c)

for i in range(len(f)):
    f[i][0] = [change(c) for c in f[i][0]]

f.sort(key=cmp)
ans = 0
for i, j in enumerate(f, 1):
    ans += i * j[1]
print(ans)