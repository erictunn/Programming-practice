# must take first place in each of 5 lines, first 4 will be multi digit nums and last is an operator, and apply operator to those 4 digits. repeat throughout the whole input
# I will take each line into a list, then each place will become a list
# Then I will iterate through each index of the list.





with open('/Users/Eric/Documents/Projects/adventofcode/input.txt') as input:
    lines = input.read().splitlines()
    
    grid = [line.split() for line in lines]

totalcount = 0

for x in range (len(grid[0])):
    y = len(grid) - 1
    if grid[y][x] == "*":
        operation = "*"
        current_calc = 1    # start from 1 because 0 * a * b != ab 
    else:
        operation = "+"
        # operation = "+" so we start from 0
        current_calc = 0
    for y in range(len(grid) - 1):
        if operation == "*":
            current_calc = current_calc * int(grid[y][x])
        else: # if operation == "+"
            current_calc += int(grid[y][x])

    totalcount += current_calc

print(totalcount)