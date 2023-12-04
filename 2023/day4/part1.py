import os
with open(os.path.dirname(__file__) + "/input.in") as file:
    f = file.read().split('\n')

ans = 0
for line in f:
    line = line.split(": ")[1]
    win, cards = line.split(" | ")
    win = list(map(int, win.split()))
    cards = list(map(int, cards.split()))
    cur = -1
    for x in win:
        if x in cards:
            cur += 1

    if cur > -1:
        ans += (1 << cur)

print(ans)