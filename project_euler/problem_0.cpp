// Calculate sum of n^2 for odd n between 1 and 750,000 inclusive
// Or alternatively, iterate through the sequence 1, 3 ... 749999

# include <iostream>

int main () {
    long long total = 0;
    for (long long n = 1; n < 750000; n+=2) {
        total += n * n;
    }
    std::cout << total << "\n";
}
