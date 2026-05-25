// Sum of n for n = 1, 2, ... 999, if n is a multiple of 3 or 5

# include <iostream>

int _sum_multiples(int max, int k) {
    int n = max / k;
    return n * (n + 1) * k * 0.5;
}

int main() {
    int max = 999;
    int total = _sum_multiples(max, 3)
                + _sum_multiples(max, 5)
                - _sum_multiples(max, 15);
    std::cout << total << std::endl;
}
