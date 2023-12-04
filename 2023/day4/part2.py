import os, collections
with open(os.path.dirname(__file__) + "/input.in") as file:
    f = file.read().split('\n')

cnt = collections.defaultdict(int)
for line in f:
    id, line = line.split(": ")
    win, cards = line.split(" | ")
    win = list(map(int, win.split()))
    cards = list(map(int, cards.split()))
    cur = 0
    for x in win:
        if x in cards:
            cur += 1

    id = int(id.split()[1])
    cnt[id] += 1
    for i in range(id + 1, id + cur + 1):
        cnt[i] += cnt[id]

ans = 0
for x in cnt:
    ans += cnt[x]
print(ans)