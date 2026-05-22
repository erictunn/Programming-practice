// Solution for Advent of Code 2025, Day 2, Part 1.

# include <fstream>
# include <iostream>
# include <string>
# include <sstream>


long long find_invalid_IDS(long long start, long long end) {
    long long range_total = 0;
    for (long long i = start; i < end + 1; i++) {
        std::string str_i = std::to_string(i);
        int len = str_i.length();
        if (len % 2 != 0) {
            continue;
        }
        std::string half1 = str_i.substr(0, len / 2);
        std::string half2 = str_i.substr(len / 2);
        if (half1 == half2) {
            range_total += i;
        }
    }
    return range_total;
}


int main() {
    std::fstream input_file("input.txt");
    std::string r;
    long long total = 0;
    while (std::getline(input_file, r, ',')) {
        std::stringstream ss(r);
        std::string start_str, end_str;
        std::getline(ss, start_str, '-');
        std::getline(ss, end_str, '-');
        long long start = std::stoll(start_str);
        long long end = std::stoll(end_str);
        total += find_invalid_IDS(start, end);
    }

    std::cout << total << "\n";
    return 0;
}
