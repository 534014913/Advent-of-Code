#include <cctype>
#include <cstdio>
#include <fstream>
#include <iostream>
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

int find_in_line(std::string line, bool forward) {
  if (!forward) {
    reverse(line.begin(), line.end());
  }
  for (auto c : line) {
    if (std::isdigit(c)) {
      return c - '0';
    }
  }
  return 0;
}

int main() {
  std::cin.sync_with_stdio(0);
  std::cin.tie(0);
  std::ifstream input("day1.txt");
  std::string line;
  int total_value = 0;
  while (std::getline(input, line)) {
    total_value += 10 * find_in_line(line, true) + find_in_line(line, false);
  }
  std::cout << total_value << std::endl;
  return 0;
}