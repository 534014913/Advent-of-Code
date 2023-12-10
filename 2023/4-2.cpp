#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cctype>
#include <iterator>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

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
    int n = 0;
    while (std::getline(input, line)) {
        n++;
    }

    std::vector<int> card_to_cpy(n, 1);
    input = std::ifstream("day4.txt");
    while (std::getline(input, line)) {
        std::stringstream line_ss(line);
        std::string sub_line;
        int card_no;

        std::getline(line_ss, sub_line, ':');
        sscanf(sub_line.c_str(), "Card %d", &card_no);
        // std::cout << "crd: " << card_no << std::endl;

        std::getline(line_ss, sub_line, ':');
        std::stringstream sub_line_ss(sub_line);
        std::string winning;
        std::getline(sub_line_ss, winning, '|');
        // std::cout << winning << std::endl;
        std::stringstream winning_ss(winning);

        std::string own;
        std::getline(sub_line_ss, own, '|');
        // std::cout << own << std::endl;
        std::stringstream own_ss(own);

        std::set<int> winning_set;
        int matches = 0;
        int num;
        while (winning_ss >> num) {
            winning_set.insert(num);
        }

        while (own_ss >> num) {
            // std::cout << num << " ";
            if (winning_set.find(num) != winning_set.end()) {
                matches++;
            }
        }

        // std::cout << matches << std::endl;

        for (int i = card_no ; i < card_no + matches; i++) {
            // std::cout << i << "+=" << card_to_cpy[card_no-1] << std::endl;
            card_to_cpy[i] += card_to_cpy[card_no-1];
        }
    }
        // for (auto item : card_to_cpy) {
        //     std::cout << item << std::endl;
        // }
    std::cout << std::reduce(card_to_cpy.cbegin(), card_to_cpy.cend()) << std::endl;
    return 0;
}