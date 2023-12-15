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

print(sum([hash(line) for line in f]))