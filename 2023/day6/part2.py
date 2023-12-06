import os
with open(os.path.dirname(__file__) + "/input.in") as file:
    f = file.read().split('\n')

time = int(''.join(f[0].split()[1:]))
dist = int(''.join(f[1].split()[1:]))

i, j = 1, time - 1
while (time - i) * i <= dist: i += 1
while (time - j) * j <= dist: j -= 1
print(j - i + 1)