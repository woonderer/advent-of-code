import os
with open(os.path.dirname(__file__) + "/input.in") as file:
    workflow, f = list(map(lambda x: x.split(), (file.read().strip().split('\n\n'))))

g = dict()
for line in workflow:
    name, rest = line[:line.find('{')], line[line.find('{') + 1:-1].split(',')
    g[name] = rest

def solve(cur = "in", min_x = 1, max_x = 4000, min_m = 1, max_m = 4000, min_a = 1, max_a = 4000, min_s = 1, max_s = 4000):
    if cur == 'R' or min_x > max_x or min_m > max_m or min_a > max_a or min_s > max_s: return 0
    elif cur == 'A': 
        return (max_x - min_x + 1) * (max_m - min_m + 1) * (max_a - min_a + 1) * (max_s - min_s + 1)

    ans = 0
    for check in g[cur][:-1]:
        rule, where = check.split(':')
        variable, sign, num = rule[0], rule[1], int(rule[2:])
        match variable:
            case 'x': 
                if sign == '>':
                    ans += solve(where, num + 1, max_x, min_m, max_m, min_a, max_a, min_s, max_s)
                    max_x = num
                else:
                    ans += solve(where, min_x, num - 1, min_m, max_m, min_a, max_a, min_s, max_s)
                    min_x = num
            case 'm': 
                if sign == '>':
                    ans += solve(where, min_x, max_x, num + 1, max_m, min_a, max_a, min_s, max_s)
                    max_m = num
                else:
                    ans += solve(where, min_x, max_x, min_m, num - 1, min_a, max_a, min_s, max_s)
                    min_m = num
            case 'a': 
                if sign == '>':
                    ans += solve(where, min_x, max_x, min_m, max_m, num + 1, max_a, min_s, max_s)
                    max_a = num
                else:
                    ans += solve(where, min_x, max_x, min_m, max_m, min_a, num - 1, min_s, max_s)
                    min_a = num
            case 's': 
                if sign == '>':
                    ans += solve(where, min_x, max_x, min_m, max_m, min_a, max_a, num + 1, max_s)
                    max_s = num
                else:
                    ans += solve(where, min_x, max_x, min_m, max_m, min_a, max_a, min_s, num - 1)
                    min_s = num
    
    return ans + solve(g[cur][-1], min_x, max_x, min_m, max_m, min_a, max_a, min_s, max_s)

print(solve())