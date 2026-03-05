'''
Split input into individual characters, find columns of spaces to separate calculations then feed it into a function
'''


def solvecalc(startx, endx):
    numbers = []
    is_add = False
    for i in range(startx, endx + 1):
        if grid[-1][i] == "+":
            is_add = True
    
    '''
    is_add = grid[-1][startx] == "+" 
    '''
    current_calc = 0 if is_add else 1

    for x in range (endx, startx - 1, -1):
        columndigit = ""
        
        for y in range (len(grid)):

            if grid[y][x].isdigit():
                columndigit += grid[y][x]
            
        if columndigit:
            numbers.append(int(columndigit))
    
    if is_add:
        return sum(numbers)
    
    else:
        for number in numbers:
            current_calc = current_calc * number

    return current_calc




with open('input.txt') as input:
    lines = input.read().splitlines()
    
    grid = [list(line) for line in lines]

totalcount = 0
startx = 0

for x in range (len(grid[0]) + 1):
    
    if x == len(grid[0]) or all(row[x] == ' ' for row in grid):
            totalcount += solvecalc(startx, x - 1)
            startx = x + 1
    

print(totalcount)
        