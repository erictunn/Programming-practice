// Sum of fibonacci numbers < 4 million and even.

# include <iostream>

int main() {
    long long total = 0;
    long long current = 2;
    long long previous = 1;
    long long next = 0;
    long long less_than = 0;
    std::cin >> less_than;

    while (current <= less_than) {
        if (current % 2 == 0) {
            total += current;
        }
        next = current + previous;
        previous = current;
        current = next;
    }
    std::cout << total << "\n";
}
