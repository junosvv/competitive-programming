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
        string s;
        cin >> n >> s;
        string t;
        FOR(i, 0, n) {
            if (!t.empty() && s[i] != t.back()) t.pop_back();
            else t += s[i];
        }
        cout << t.size() << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}