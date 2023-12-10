#include <fstream>
#include <iostream>
#include <cctype>
#include <string>
#include <utility>
#include <cassert>
#include <set>

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

const std::set<char> symbols = {'*', '#'};

int read_num(std::vector<std::vector<char>> &grid, int i, int j) {
    assert(std::isdigit(grid[i][j]));
    int res = 0;
    while (j < grid[i].size() && std::isdigit(grid[i][j])) {
        res = 10 * res + (grid[i][j] - '0');
        j++;
    }
    // std::cout << res << std::endl;
    return res;
}

bool is_part(std::vector<std::vector<char>> &grid, int i, int j) {
    bool is_part = false;
    while (j < grid[i].size() && isdigit(grid[i][j])) {
        // std::cout << "here" << std::endl;
        grid[i][j] = '.';
        for (int x = -1; x <= 1; x++) {
            for (int y = -1; y <= 1; y++) {
                int nx = i + x;
                int ny = j + y;
                if (0 <= nx && nx < grid.size() && 0 <= ny && ny < grid[i].size()) {
                    if (!isdigit(grid[nx][ny]) && grid[nx][ny] != '.') {
                        is_part = true;
                    } 
                }
            }
        }
        j++;
    }

    return is_part;
}


int main() {
    std::cin.sync_with_stdio(0);
    std::cin.tie(0);
    std::ifstream input("day3.txt");
    std::string line;
    int h = 0, w = 0;
    while (std::getline(input, line)) {
        w = line.size();
        h++;
    }

    std::vector<std::vector<char>> grid(h, std::vector<char>(w, '.'));
    input = std::ifstream("day3.txt");
    h = 0;
    while (std::getline(input, line)) {
        for (size_t i = 0; i < line.size(); i++) {
            grid[h][i] = line[i];
        }
        h++;
    }

    int sum = 0;

    for (size_t i = 0; i < grid.size(); i++) {
        for (size_t j = 0; j < grid[0].size(); j++) {
            // std::cout << grid[i][j];
            int num = 0;
            if (std::isdigit(grid[i][j])) {
                num = read_num(grid, i, j);
                // std::cout << num << std::endl;
                if (is_part(grid, i, j)) {
                    sum += num;
                }
            }
        }
        // std::cout << std::endl;
    }

    std::cout << sum << std::endl;
    return 0;
}