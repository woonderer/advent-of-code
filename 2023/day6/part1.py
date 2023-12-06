import os
with open(os.path.dirname(__file__) + "/input.in") as file:
    f = file.read().split('\n')

time = list(map(int, f[0].split()[1:]))
dist = list(map(int, f[1].split()[1:]))

ans = 1
for i in range(len(time)):
    ans *= math.floor((time[i] + math.sqrt(time[i] * time[i] - 4 * dist[i])) / 2) - math.ceil((time[i] - math.sqrt(time[i] * time[i] - 4 * dist[i])) / 2) + 1
print(ans)
