// Find all values of n when the Collatz algorithm is applied to it, for n < 10^6

# include <iostream>

int main() {
    unsigned long long n = 0;
    std::cin >> n;
    while (n > 1) {
        std::cout << n << " ";
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = n * 3 + 1;
        }
    }
    std::cout << n;
}
