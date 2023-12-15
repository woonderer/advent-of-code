import os
with open(os.path.dirname(__file__) + "\\input.in") as file:
    f = file.read().strip().split(',')

def hash(s):
    ans = 0
    for c in s:
        ans += ord(c)
        ans *= 17
        ans %= 256
    return ans

box = [[] for _ in range(256)]

for line in f:
    if line[-1] == '-':
        label = line[:-1]
        h = hash(label)
        for i in range(len(box[h])):
            if box[h][i][0] == label:
                box[h].pop(i)
                break
    else:
        label, id = line.split('=')
        h = hash(label)
        add = False
        for i in range(len(box[h])):
            if box[h][i][0] == label:
                box[h][i][1] = int(id)
                add = True
                break
        
        if not add: box[h].append([label, int(id)])

ans = 0
for i, b in enumerate(box, 1):
    for j, slot in enumerate(b, 1):
        ans += i * j * slot[1]
print(ans)