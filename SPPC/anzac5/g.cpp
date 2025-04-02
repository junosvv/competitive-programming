#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define lg long long

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    char turn;
    cin >> turn;

    while (turn != '#') {
        vector<string> grid(3, string(3, '.'));
        char c;
        string res = "Draw";
        while (true) {
            cin >> c;
            if (c == 'X' || c == 'O' || c == '#') break;
            int x = stoi(string(1, c));
            --x;

            int r = x/3;
            int c = x%3;
            grid[r][c] = turn;
            if (turn == 'X') turn = 'O';
            else turn = 'X';

            if (res == "Draw") {
                FOR(r, 0, 3) if (grid[r][0] != '.' && grid[r][0] == grid[r][1] && grid[r][1] == grid[r][2]) res = grid[r][0];
                FOR(c, 0, 3) if (grid[0][c] != '.' && grid[0][c] == grid[1][c] && grid[1][c] == grid[2][c]) res = grid[0][c];
                if (grid[0][0] != '.' && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) res = grid[0][0];
                if (grid[0][2] != '.' && grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) res = grid[0][2];
            }
        }
        turn = c;
        cout << res << '\n';
    }
}