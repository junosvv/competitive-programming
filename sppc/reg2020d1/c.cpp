#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int R, C, Y;
    cin >> R >> C >> Y;
    int K = max(Y, C-Y);

    vector<string> res(R, string(K, 'o'));
    FOR(r, 0, R) {
        string s;
        cin >> s;
        FOR(i, Y, C) if (s[i] == 'x') res[r][i-Y] = 'x';
        ROF(i, Y-1, -1) if (s[i] == 'x') res[r][Y-1-i] = 'x';
        reverse(res[r].begin(), res[r].end());
    }

    for (string s : res) cout << s << '\n';
}