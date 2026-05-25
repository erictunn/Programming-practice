// Solution for Advent of Code, Day 2, Part 2

# include <fstream>
# include <iostream>
# include <string>
# include <sstream>

static std::string repeat_string(const std::string& s, int times) {
    if (times <= 0) {
        return "";
    }
    std::string out;
    out.reserve(s.size() * static_cast<size_t>(times));
    for (int i = 0; i < times; i++) {
        out += s;
    }
    return out;
}
// TODO: Fix - overshooting result.
long long find_invalid_IDS(long long start, long long end) {
    long long range_total = 0;
    for (long long i = start; i < end + 1; i++) {
        std::string str_i = std::to_string(i);
        int len = static_cast<int>(str_i.length());
        for (int repeat = 2; repeat <= len; repeat++) {
            if (len % repeat != 0) {
                continue;
            }
            int chunk_len = len / repeat;
            std::string chunk = str_i.substr(0, chunk_len);
            if (repeat_string(chunk, repeat) == str_i) {
                range_total += i;
            }
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
        std::getline(ss, end_str);
        long long start = std::stoll(start_str);
        long long end = std::stoll(end_str);
        total += find_invalid_IDS(start, end);
    }

    std::cout << total << "\n";
    return 0;
}
