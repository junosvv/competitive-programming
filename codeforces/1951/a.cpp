#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    auto solve = [&]() {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int cnt = 0, first = -1, last = -1;
        FOR(i, 0, n) {
            if (s[i] == '1') {
                ++cnt;
                last = i;
                if (first == -1) first = i;
            }
        }

        if (cnt == 2) {
            cout << (first + 1 == last ? "NO" : "YES") << '\n';
            return;
        }

        cout << (cnt&1 ? "NO" : "YES") << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}