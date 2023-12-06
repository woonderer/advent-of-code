import os
with open(os.path.dirname(__file__) + "/input.in") as file:
    f = file.read().split('\n')

time = list(map(int, f[0].split()[1:]))
dist = list(map(int, f[1].split()[1:]))

ans = 1
for i in range(len(time)):
    cnt = 0
    for j in range(1, time[i] + 1):
        if (time[i] - j) * j > dist[i]:
            cnt += 1
    ans *= cnt
print(ans)