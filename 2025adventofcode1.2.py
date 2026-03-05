dialpointsto = 50
past100count = 0
def opensafe(dialchange):
    global dialpointsto
    global past100count
    if dialchange[0] == "L":
        dialchange= int("-" + dialchange[1:])
        for x in range (0, dialchange, -1):
            dialpointsto -= 1
            if dialpointsto % 100 == 0:
                past100count +=1
    else:
        dialchange = int(dialchange[1:])
        for x in range (0, dialchange):
            dialpointsto += 1
            if dialpointsto % 100 == 0:
                past100count +=1
import fileinput
with open('input.txt') as f:
    for line in f:
        dialchange = line.strip()
        opensafe(dialchange)
print(past100count)