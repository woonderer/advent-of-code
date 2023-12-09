import os
with open(os.path.dirname(__file__) + "\\input.in") as file:
    f = file.read().strip().split('\n')

def solve(T):
    return 0 if len(set(T)) == 1 and 0 in T else T[-1] + solve([T[i] - T[i - 1] for i in range(1, len(T))])

print(sum(solve(list(map(int, line.split()))) for line in f))