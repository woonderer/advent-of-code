import os
with open(os.path.dirname(__file__) + "/input.in") as file:
    f = file.read().split('\n')

time = int(''.join(f[0].split()[1:]))
dist = int(''.join(f[1].split()[1:]))

print(math.floor((time + math.sqrt(time * time - 4 * dist)) / 2) - math.ceil((time - math.sqrt(time * time - 4 * dist)) / 2) + 1)
