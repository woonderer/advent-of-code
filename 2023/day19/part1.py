import os
with open(os.path.dirname(__file__) + "/input.in") as file:
    workflow, f = list(map(lambda x: x.split(), (file.read().strip().split('\n\n'))))

g = dict()
for line in workflow:
    name, rest = line[:line.find('{')], line[line.find('{') + 1:-1].split(',')
    g[name] = rest

ans = 0
for line in f:
    v = dict()
    for x in line[1:-1].split(','):
        v[x[0]] = int(x[2:])
    
    cur = "in"
    while cur != 'R' and cur != 'A':
        moved = False
        for check in g[cur][:-1]:
            rule, where = check.split(':')
            variable, sign, num = rule[0], rule[1], rule[2:]
            if sign == '>':
                if v[variable] > int(num):
                    cur = where
                    moved = True
                    break
            else:
                if v[variable] < int(num):
                    cur = where
                    moved = True
                    break
        
        if not moved: cur = g[cur][-1]
    
    if cur == 'A': ans += sum(list(v.values()))

print(ans)