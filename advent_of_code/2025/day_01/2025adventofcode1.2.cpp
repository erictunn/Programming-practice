// Solution for Advent of Code 2025, Day 1, Part 25.
# include <fstream>
# include <iostream>
# include <string>

int _single_change(std::string dialchange, int& d) {
    char direction = dialchange[0];
    int magnitude = std::stoi(dialchange.substr(1));
    int passes = 0;
    if (direction == 'L') {
        for (int i = 0; i < magnitude; i++) {
            d -= 1;
            if (d % 100 == 0) {
                passes += 1;
            }
        }
    }   else if (direction == 'R') {
        for (int i = 0; i < magnitude; i++) {
            d+=1;
            if (d % 100 == 0) {
                passes += 1;
            }
        }
    }
    return passes;
}

int main() {
    int dial_pos = 50;
    int past_100_count = 0;
    std::fstream input_file("input.txt");
    std::string line;

    while (std::getline(input_file, line)) {
        past_100_count += _single_change(line, dial_pos);
    }

    std::cout << past_100_count << "\n";
    return 0;
}
