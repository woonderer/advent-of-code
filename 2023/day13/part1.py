import os
with open(os.path.dirname(__file__) + "/input.in") as file:
    f = [pattern.split() for pattern in file.read().strip().split('\n\n')]

def vertical(T):
    ans = 0
    for i in range(len(T[0]) - 1):
        good = True
        for line in T:
            l, r = i, i + 1
            while l >= 0 and r < len(T[0]):
                if line[l] != line[r]:
                    good = False
                    break

                l -= 1
                r += 1

            if not good: break

        if good: ans += i + 1

    return ans

def horizontal(T):
    ans = 0
    for i in range(len(T) - 1):
        good = True
        for j in range(len(T[0])):
            l, r = i, i + 1
            while l >= 0 and r < len(T):
                if T[l][j] != T[r][j]:
                    good = False
                    break

                l -= 1
                r += 1

            if not good: break

        if good: ans += i + 1

    return ans

ans = 0
for pattern in f:
    ans += 100 * horizontal(pattern) + vertical(pattern)
print(ans)