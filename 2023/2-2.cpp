#include <cstdio>
#include <fstream>
#include <iostream>
#include <istream>
#include <sstream>
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



int main() {
    std::cin.sync_with_stdio(0);
    std::cin.tie(0);
    std::ifstream input("day2.txt");
    std::string game_entry;
    ll sum = 0;
    // Game <n>:
    while (std::getline(input, game_entry)) {
        int r = 0, g = 0, b = 0;
        std::istringstream game_entry_ss(game_entry);
        std::string game;
        std::getline(game_entry_ss, game, ':');
        int game_no;
        sscanf(game.c_str(), "Game %d", &game_no);

        std::getline(game_entry_ss, game, ':');
        std::istringstream game_ss(game);
        std::string subgame;
        while (std::getline(game_ss, subgame, ';')) {
            std::istringstream subgame_ss(subgame);
            std::string subgame_item;
            while (std::getline(subgame_ss, subgame_item, ',')) {
                std::string c;
                int n;
                std::istringstream subgame_item_ss(subgame_item);
                subgame_item_ss >> n >> c;
                if (c == "green") {
                    g = std::max(g, n);
                } else if (c == "red") {
                    r = std::max(r, n);
                } else if (c == "blue") {
                    b = std::max(b, n);
                }
            }
        }
        // std::cout << r * g * b << std::endl;
        sum += r * g * b;
    }
    std::cout << sum << std::endl;
    return 0;
}