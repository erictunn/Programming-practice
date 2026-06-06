// Find the nth prime.
// Using: sieve of Eratosthenes.

# include <iostream>
# include <cmath>
# include <vector>

int estimate_upper_bound(int n) {
    unsigned int ub = n * (std::log(n) + std::log(std::log(n)));
    return ub;
}

std::vector<unsigned long> prime_sieve(unsigned long ub) {
    std::vector<bool> sieve((ub + 1) / 2, true);
    for (unsigned long i = 3; i * i <= ub; i += 2) {
        if (sieve[i >> 1]) {
            for (unsigned long j = i * i; j <= ub; j += 2 * i) {
                sieve[j >> 1] = false;
            }
        }
    }

    std::vector<unsigned long> primes = {2};
    for (unsigned long i = 3; i <= ub; i += 2) {
        if (sieve[i >> 1]) {
            primes.push_back(i);
        }
    }
    return primes;
}

int main () {
    unsigned long n = 0;
    std::cout << "enter number ";
    std::cin >> n;
    unsigned long upper_bound = estimate_upper_bound(n);
    std::vector<unsigned long> primes = prime_sieve(upper_bound);
    std::cout << primes[n - 1] << "\n";
    return 1;
}
