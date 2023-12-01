import os
with open(os.path.dirname(__file__) + "\\input.in") as file:
    f = file.read().split('\n')

d = {
    "one": '1',
    "two": '2',
    "three": '3',
    "four": '4',
    "five": '5',
    "six": '6',
    "seven": '7',
    "eight": '8',
    "nine": '9'
}

ans = 0
for s in f:
    fst, lst = -1, -1
    for i in range(len(s)):
        if s[i] in '0123456789':
            if fst == -1: fst = s[i]
            lst = s[i]
        
        for key in d.keys():
            if s[i:i+len(key)] == key:
                if fst == -1: fst = d[key]
                lst = d[key]
    ans += int(fst + lst)
print(ans)