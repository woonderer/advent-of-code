import os
with open(os.path.dirname(__file__) + "\\input.in") as file:
    f = file.read().split('\n')

ans = 0
for line in f:
    line = line.replace("Game ", "")
    line = line.replace(": ", "; ")
    line = line.split("; ")
    id = int(line[0])
    line = line[1:]

    cnt = 0
    for game in line:
        red, green, blue = 0, 0, 0
        for g in game.split(", "):
            ile, color = g.split()
            if color == "red":
                red += int(ile)
            if color == "green":
                green += int(ile)
            if color == "blue":
                blue += int(ile)
        
        if red <= 12 and green <= 13 and blue <= 14:
            cnt += 1

    if cnt == len(line):
        ans += id

print(ans)