import os
with open(os.path.dirname(__file__) + "/input.in") as file:
    f = file.read().strip().split('\n\n')

seeds = list(map(int, f[0].split()[1:]))
mapping = [[list(map(int, line.split())) for line in f[i].split('\n')[1:]] for i in range(1, 8)]
ranges = [[seeds[i], seeds[i] + seeds[i + 1] - 1] for i in range(0, len(seeds), 2)]

def solve(start, end, idx = 0):
    if idx == 7:
        return start
    
    intervals = []
    for dest, source, lenght in mapping[idx]:
        pos_start, pos_end = max(start, source), min(end, source + lenght - 1)
        if pos_start <= pos_end: intervals.append((pos_start, pos_end, dest, source))
    
    ans = []
    for s, e, dest, source in intervals:
        ans.append(solve(dest + s - source, dest + e - source, idx + 1))
    
    intervals.append((start - 1, start - 1, -1, -1))
    intervals.append((end + 1, end + 1, -1, -1))
    intervals = sorted(intervals)
    for i in range(len(intervals) - 1):
        e1, s2 = intervals[i][1], intervals[i + 1][0]
        if s2 - e1 > 1: ans.append(solve(e1 + 1, s2 - 1, idx + 1))
    
    return min(ans)
                
ans = []
for start, end in ranges:
    ans.append(solve(start, end))
print(min(ans))