import os, heapq
with open(os.path.dirname(__file__) + "\\input.in") as file:
    f = file.read().strip().split('\n')

n, m = len(f), len(f[0])
ans = [[[-1 for _ in range(2)] for _ in range(m)] for _ in range(n)]
q = []

heapq.heappush(q, (0, 0, 0, 0))
heapq.heappush(q, (0, 0, 0, 1))
while ans[n - 1][m - 1][0] == -1 and ans[n - 1][m - 1][1] == -1:
    heat, y, x, mode = heapq.heappop(q)
    if ans[y][x][mode] != -1: continue
    ans[y][x][mode] = heat

    if mode:
        s1, s2 = 0, 0
        for k in range(1, 4):
            if y - k >= 0:
                s1 += int(f[y - k][x])
                heapq.heappush(q, (heat + s1, y - k, x, not mode))
            if y + k < n:
                s2 += int(f[y + k][x])
                heapq.heappush(q, (heat + s2, y + k, x, not mode))
    else:
        s1, s2 = 0, 0
        for k in range(1, 4):
            if x - k >= 0:
                s1 += int(f[y][x - k])
                heapq.heappush(q, (heat + s1, y, x - k, not mode))
            if x + k < m:
                s2 += int(f[y][x + k])
                heapq.heappush(q, (heat + s2, y, x + k, not mode))

print(max(ans[n - 1][m - 1][0], ans[n - 1][m - 1][1]))