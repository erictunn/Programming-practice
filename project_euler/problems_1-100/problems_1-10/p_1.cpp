// Sum of n for n = 1, 2, ... 999, if n is a multiple of 3 or 5

# include <iostream>

// With a modern compiler, these two solutions should compile to roughly the same binary.

int main() {
    int total = 0;
    int n = 0;
    int n_less_than = 0;
    std::cin >> n_less_than;
    for (int n = 0; n < 1000; n++) {
        if (n % 3 == 0 or n % 5 == 0) {
            total += n;
        }
    }
    std::cout << total << "\n";
}


int _sum_multiples(int max, int k) {
    int n = max / k;
    return n * (n + 1) * k * 0.5;
}

void main_b() {
    int max = 0;
    std::cin >> max;
    max -= 1;
    int total = _sum_multiples(max, 3)
              + _sum_multiples(max, 5)
              - _sum_multiples(max, 15);
    std::cout << total << "\n";
}
