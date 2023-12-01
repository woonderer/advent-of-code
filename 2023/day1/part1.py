import os
with open(os.path.dirname(__file__) + "\\input.in") as file:
    f = file.read().split('\n')

ans = 0
for s in f:
    fst, lst = -1, -1
    for i in range(len(s)):
        if s[i] in '0123456789':
            if fst == -1: fst = i
            lst = i
    ans += int(s[fst] + s[lst])
print(ans)