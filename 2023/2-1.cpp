#include <fstream>
#include <iostream>
#include <cctype>
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


const int RED = 12, GREEN = 13, BLUE = 14;

int main() {
    std::cin.sync_with_stdio(0);
    std::cin.tie(0);
    std::ifstream input("day2.txt");
    std::string line;
    auto sum = 0;
    while (std::getline(input, line)) {
        std::istringstream ss(line);
        std::string token;
        std::getline(ss, token, ':');
        // token here is Game x
        // std::cout << token << std::endl;
        int game_no;
        sscanf(token.c_str(), "Game %d", &game_no);
        // std::cout << game_no << std::endl;

        std::getline(ss, token, ':');
        std::string subgame;
        std::stringstream game(token);
        bool valid = true;
        while (std::getline(game, subgame, ';')) {
            std::istringstream subgame_ss(subgame);
            std::string ball;
            while (std::getline(subgame_ss, ball, ',')) {
                // std::cout << ball << std::endl;
                std::stringstream ball_ss(ball);
                int ball_num;
                std::string ball_col;
                ball_ss >> ball_num >> ball_col;
                if (ball_col == "green" && ball_num > GREEN) {
                    valid = false;
                } else if (ball_col == "red" && ball_num > RED) {
                    valid = false;
                } else if (ball_col == "blue" && ball_num > BLUE) {
                    valid = false;
                }
            }
        }
        if (valid) sum += game_no;
    }
    std::cout << sum << std::endl;
    return 0;
}