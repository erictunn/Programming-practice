absolute_fresh_count = 0
ranges = []
merged_ranges = []
def merge_ranges(ranges):
    global merged_ranges
    last_end = 0
    last_start = 0
    for this_start, this_end in ranges:
        if this_start <= last_end:
            this_start = last_start
            this_end = max(this_end, last_end)
            del merged_ranges[-1]

        merged_ranges.append((this_start, this_end))
        last_start = this_start
        last_end = this_end

with open('input.txt') as input:
    for line in input: 
        line = line.strip()
        if not line: # blank line marks change from ranges to IDs. IDs are irrelevant for this
            break
        start, end = map(int, line.split('-'))
        ranges.append((start, end))

ranges.sort()

merge_ranges(ranges)

for start, end in merged_ranges:
    absolute_fresh_count += end +1 - start

print(absolute_fresh_count)