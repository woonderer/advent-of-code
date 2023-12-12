import os
with open(os.path.dirname(__file__) + "/input.in") as file:
    f = file.read().strip().split('\n')

dp = {}
def solve(dots, blocks, idx = 0, idx_b = 0, cur = 0):
    state = (idx, idx_b, cur)
    if state in dp: return dp[state]
    if idx == len(dots):
        if idx_b == len(blocks) and cur == 0: return 1
        if idx_b == len(blocks) - 1 and cur == blocks[idx_b]: return 1
        return 0

    ans = 0
    for c in ('.', '#'):
        if c == dots[idx] or dots[idx] == '?':
            if c == '.' and cur == 0: ans += solve(dots, blocks, idx + 1, idx_b, cur)
            elif c == '.' and cur > 0 and idx_b < len(blocks) and cur == blocks[idx_b]: ans += solve(dots, blocks, idx + 1, idx_b + 1, 0)
            elif c == '#': ans += solve(dots, blocks, idx + 1, idx_b, cur + 1)

    dp[state] = ans
    return ans


ans = 0
for line in f:
    dots, blocks = line.split()
    dots, blocks = '?'.join([dots, dots, dots, dots, dots]), list(map(int, ', '.join([blocks, blocks, blocks, blocks, blocks]).split(',')))
    dp.clear()
    ans += solve(dots, blocks)
print(ans)