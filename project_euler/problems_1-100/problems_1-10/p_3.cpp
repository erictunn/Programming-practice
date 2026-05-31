// Find the largest prime factor of input.

# include <iostream>


int main() {
    unsigned long long input = 0;
    std::cout << "enter number ";
    std::cin >> input;
    unsigned long long largest = 0;
    while (input % 2 == 0) {
        largest = 2;
        input /= 2;
    }
    for (unsigned long long i = 3; i * i < input; i+=2) {
        while (input % i == 0) {
            largest = i;
            input /= i;
        }
    }
    if (input > 2) {
        largest = input;
    }
    std::cout << "\n" << largest;
}
