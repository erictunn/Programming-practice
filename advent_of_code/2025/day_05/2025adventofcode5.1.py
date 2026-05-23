fresh_ranges = []
fresh_count = 0
input_is_ranges = True
def solve_ranges(start, end):
    global fresh_ranges
    fresh_ranges.append((start, end))
def solve_IDs(line):
    global fresh_count
    ID = int(line)
    for start, end in fresh_ranges:
        if start <= ID <= end:
            fresh_count += 1
            return

with open('input.txt') as input:
    for line in input:
        line = line.strip()
        if not line:
            input_is_ranges = False
            continue
        if input_is_ranges:
            start, end = map(int, line.split('-'))
            solve_ranges(start, end)
        else:
            solve_IDs(line)
print(fresh_count)