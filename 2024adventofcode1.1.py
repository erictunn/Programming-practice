
def finddif(a, b):
    dif = abs(a - b)
    return dif

col1 = []
col2 = []


with open('input.txt') as input: # taking input
    for pairs in input:
        x, y = map(int, pairs.split())
        col1.append(x)
        col2.append(y)

col1.sort()
col2.sort()

totaldif = 0

for a, b in zip(col1, col2):
    totaldif += finddif(a, b)

print (totaldif)