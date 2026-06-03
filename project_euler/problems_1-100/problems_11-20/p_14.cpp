// Find the longest sequence in the Collatz for any int n[0] < value.

# include <iostream>

int collatz_length_solver(int start) {
    int length = 1;
    unsigned long long n = start;
    while (n > 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n *= 3;
            n += 1;
        }
        length += 1;
    }
    return length;
}

int main() {
    unsigned long long start_max = 0;
    std::cout << "enter max ";
    std::cin >> start_max;
    unsigned long long longest_num;
    unsigned long long longest = 0;
    for (unsigned long long start = 0; start <= start_max; start++) {
        int len = collatz_length_solver(start);
        if (len > longest) {
            longest = len;
            longest_num = start;
        }
    }
    std::cout << "\n" << longest;
    std::cout << "\n" << longest_num;
}
