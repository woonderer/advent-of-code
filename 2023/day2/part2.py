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
 
    red, green, blue = 0, 0, 0
    for game in line:
        for xd in game.split(", "):
            ile, color = xd.split(" ")
            if color == "red":
                red = max(red, int(ile))
            if color == "green":
                green = max(green, int(ile))
            if color == "blue":
                blue = max(blue, int(ile))
    ans += red * green * blue
        
print(ans)