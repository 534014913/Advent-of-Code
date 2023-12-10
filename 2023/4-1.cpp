#include <fstream>
#include <iostream>
#include <cctype>
#include <set>
#include <sstream>
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

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;



int main() {
    std::cin.sync_with_stdio(0);
    std::cin.tie(0);
    std::ifstream input("day4.txt");
    std::string line;
    int sum = 0;
    while (std::getline(input, line)) {
        std::stringstream line_ss(line);
        std::string card_line;
        std::getline(line_ss, card_line, ':');
        std::getline(line_ss, card_line, ':');

        std::stringstream card_line_ss(card_line);
        std::string winning_nums;
        std::string own_nums;

        std::getline(card_line_ss, winning_nums, '|');
        std::getline(card_line_ss, own_nums, '|');

        std::stringstream winning_nums_ss(winning_nums);
        std::stringstream own_nums_ss(own_nums);
        std::set<int> winning_set;
        int res = 0;
        int num;
        while (winning_nums_ss >> num) {
            winning_set.insert(num);
        }

        while (own_nums_ss >> num) {
            if (winning_set.find(num) != winning_set.end()) {
                if (res == 0) {
                    res = 1;
                } else {
                    res *= 2;
                }
            }
        }
        sum += res;
    }
    std::cout << sum << std::endl;
    return 0;
}