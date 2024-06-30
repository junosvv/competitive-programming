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
        string s;
        cin >> s;
        int n = s.size();
        if (s[0] != '1') {
            cout << "NO\n";
            return;
        }
        FOR(i, 1, n-1) {
            if (s[i] == '0') {
                cout << "NO\n";
                return;
            }
        }
        if (s[n-1] == '9') {
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}