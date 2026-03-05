joltbanktotal = 0 # total outputted at end
thisjoltbank = "" # the total of this joltbank

def findtopnum(joltbankinput):
    global joltbanktotal
    digit1 = "0" # first digit that will go into thisjoltbank
    digit2 = "0" # second

    for x in range (0,len(joltbankinput)): 
        if int(joltbankinput[x]) > int(digit1) and x+1 < len(joltbankinput):
            digit1 = joltbankinput[x]
            digit2 = "0"
        elif int(joltbankinput[x]) > int(digit2):
            digit2 = joltbankinput[x]

    thisjoltbank = (digit1 + digit2) # concatenate
    joltbanktotal += int(thisjoltbank) 

    print("total:\n" + str(joltbanktotal))

import fileinput
with open('input.txt') as f:
    for line in f:
        joltbankinput = line.strip() 
        findtopnum(joltbankinput)