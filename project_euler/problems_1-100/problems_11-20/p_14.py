"""Find the longest sequence in the Collatz for any int n[0] < value.
I wrote a python version to try using built-in @cache memoisation decorator."""

from functools import cache

@cache
def collatz_length_solver(n: int) -> int:
    length = 1
    while n > 1:
        if n % 2 == 0:
            n //= 2
        else:
            n = n * 3 + 1
        length += 1
    return length

def main():
    max = int(input("num: "))
    highest = 0
    for i in range(max):
        len = collatz_length_solver(i)
        if len > highest:
            highest = len
            best_num = i
    print(best_num)

main()
