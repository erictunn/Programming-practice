total = 0
def solve_invalID(start, end):    
    invalIDs = set()
    for x in range(start, end +1): # checking each ID in range
        x = str(x)
        for pattern_len in range (1, len(x) // 2 + 1): # checking each possible pattern length of ID, pattern must always repeat 2+ times
            if len(x) % pattern_len != 0:
                continue
            pattern = x[:pattern_len]           # get first chunk of pattern
            multiplier = len(x) // pattern_len  # How many times does it fit?
            if pattern * multiplier == x:       # string multiplied repeats that string, does repeating first chunk get x again
                invalIDs.add(int(x))
    return invalIDs
with open('input.txt') as input:
    input = input.read()
    for r in input.split(","):
        start, end = map(int, r.split('-'))
        total += sum(solve_invalID(start, end))
print (total)