
def findvalid():
    def count_neighbours(y, x):
        roll_count = 0
        if grid[y][x] != "@":
            return 4
        
        for (dy, dx) in directions: # grid measured from top left, y coord is first due to grid structure
            ny, nx = dy + y, dx + x
            if 0 <= ny < rows and 0 <= nx < columns:
                if grid[ny][nx] == "@":
                    roll_count +=1
        return roll_count
    
    global this_run_valid
    global total_valid
    global grid

    this_run_valid = 0

    # directions to check 
    directions = [
        (-1, -1), (-1, 0), (-1, 1),
        (0, -1),           (0, 1),
        (1, -1),  (1, 0),  (1, 1)
    ]
    # number of rows and columns
    rows, columns = len(grid), len(grid[0])

    for y in range (rows): # r is the row number (y pos)
        for x in range (columns): # c in the column number (x pos)
            if count_neighbours(y, x) < 4:
                this_run_valid +=1
                grid[y][x] = "."

this_run_valid = 0
total_valid = 0

with open('input.txt') as input: # taking input
    lines = input.read().splitlines()
    # form a grid with the input
    grid = [list(line) for line in lines] 
    while True:
        findvalid()
        if not this_run_valid > 0:
            break
        print (this_run_valid)
        total_valid += this_run_valid
print(total_valid)