import os
with open(os.path.dirname(__file__) + "/input.in") as file:
    f = file.read().split('\n\n')

seeds = list(map(int, f[0].split()[1:]))
mapping = [[list(map(int, line.split())) for line in f[i].split('\n')[1:]] for i in range(1, 8)]

ans = []
for seed in seeds:
    for i in range(7):
        nxt = seed
        for dest, source, lenght in mapping[i]:
            if source <= seed and seed < source + lenght:
                nxt = dest + seed - source
        seed = nxt
    ans.append(seed)
print(min(ans))