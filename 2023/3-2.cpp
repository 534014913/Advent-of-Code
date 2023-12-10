#include <iostream>
#include <fstream>
#include <cctype>
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

int find_whole_num(std::vector<std::vector<char>>& grid, int i, int j) {
    while (j >= 0 && std::isdigit(grid[i][j])) {
        j--;
    }
    j++;
    int res = 0;
    while (j < grid[i].size() && std::isdigit(grid[i][j])) {
        res = 10 * res + (grid[i][j] - '0');
        grid[i][j] = '.';
        j++;
    }
    return res;
}

int find_num(std::vector<std::vector<char>>& grid, int i, int j) {
    for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
            int ni = i + di;
            int nj = j + dj;
            if (0 <= ni && ni < grid.size() && 0 <= nj && nj < grid[i].size()) {
                if (std::isdigit(grid[ni][nj])) {
                    return find_whole_num(grid, ni, nj);
                }
            }
        }
    }
    return 0;
}


int main() {
    std::cin.sync_with_stdio(0);
    std::cin.tie(0);
    std::ifstream input("day3.txt");
    std::string line;
    int w = 0, h = 0;
    while (std::getline(input, line)) {
        w = line.size();
        h++;
    }

    std::vector<std::vector<char>> grid(h, std::vector<char>(w, '0'));
    input = std::ifstream("day3.txt");
    h = 0;
    while (std::getline(input, line)) {
        for (int i = 0; i < line.size(); i++) {
            grid[h][i] = line[i];
        }
        h++;
    }

    int sum = 0;

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == '*') {
                int num1 = find_num(grid, i, j);
                int num2 = find_num(grid, i, j);
                sum += num1 * num2;
            }
        }
    }

    std::cout << sum << std::endl;
    return 0;
}