import os
with open(os.path.dirname(__file__) + "/input.in") as file:
    f = file.read().strip().split('\n')

def cross(v1, v2):
    return v1[0]*v2[1] - v1[1]*v2[0]

cur, points = [0, 0], []
for line in f:
    points.append([cur[0], cur[1]])
    d, ile, c = line.split()
    match d:
        case 'R': cur[1] += int(ile)
        case 'L': cur[1] -= int(ile)
        case 'U': cur[0] -= int(ile)
        case 'D': cur[0] += int(ile)
    
# Pick's Theorem because why not
pole, boundry = cross(points[-1], points[0]), len(points) + abs(points[-1][0] - points[0][0]) + abs(points[-1][1] - points[0][1]) - 1
for i in range(1, len(points)):
    pole += cross(points[i - 1], points[i])
    boundry += abs(points[i][0] - points[i - 1][0]) + abs(points[i][1] - points[i - 1][1]) - 1

print(boundry // 2 + abs(pole) // 2 + 1)