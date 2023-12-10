#include <algorithm>
#include <fstream>
#include <iostream>
#include <cctype>
#include <ostream>
#include <set>
#include <map>
#include <string>
#include <utility>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;
typedef std::pair<ll, int> plli;
typedef std::pair<int, ll> pill;
typedef std::pair<std::pair<int, int>, int> piii;

const std::set<std::string> numbers = {"one", "two", "three", "four", "five", "six"
                                , "seven", "eight", "nine"};
std::map<std::string, int> string_to_num = {{"one", 1}, {"two", 2},
{"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8},
{"nine", 9}};

int find_in_line(std::string line, bool is_forward) {
    if (is_forward) {
        for (size_t i = 0; i < line.size(); i++) {
            if (isdigit(line[i])) {
                return line[i] - '0';
            }
            for (size_t j = i + 1; j < line.size(); j++) {
                if (numbers.find(line.substr(i, j - i + 1)) != numbers.end()) {
                    return string_to_num[line.substr(i, j - i + 1)];
                }
            }
        }
    } else {
        for (int i = line.size() - 1; i >= 0; i--) {
            if (isdigit(line[i])) return line[i] - '0';
            for (int j = i - 1; j >= 0; j--) {
                if (numbers.find(line.substr(j, i - j + 1)) != numbers.end()) {
                    return string_to_num[line.substr(j, i - j + 1)];
                }
            }
        }
    }
    return 0;
}


int main() {
    std::cin.sync_with_stdio(0);
    std::cin.tie(0);
    std::ifstream input("day1.txt");
    std::string line;
    auto total_value = 0;
    while (std::getline(input, line)) {
        auto value = 10 * find_in_line(line, true) + find_in_line(line, false);
        // std::cout << value << std::endl;
        total_value += value;
    }
    std::cout << total_value << std::endl; 
    return 0;
}