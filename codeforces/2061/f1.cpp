#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define pii pair<int,int>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define mii map<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    const int MOD = 998244353;
    
    auto solve = [&]() {
        string s, t;
        cin >> s >> t;
        int n0 = s.size();

        vi a = {1}, b = {1};
        if (s[0] != t[0]) {
            a = {0, 1};
        }
        FOR(i, 1, n0) {
            if (s[i] != s[i-1]) a.push_back(0);
            if (t[i] != t[i-1]) b.push_back(0);
            ++a.back();
            ++b.back();
        }
        int n = a.size(), m = b.size();

        vi c(m), idx = {0, 1};
        FOR(k, 0, m) {
            int sm = 0;
            while (sm < b[k] && idx[k&1] < n) {
                sm += a[idx[k&1]];
                idx[k&1] += 2;
                ++c[k];
            }
            if (sm != b[k]) {
                cout << "-1\n";
                return;
            }
        }

        // for (int i : c) cout << i << ' ';
        // cout << '\n';

        int q = c.size();
        int res = 0;
        FOR(i, 0, q) {
            if (c[i] < 1 && i+2 < q) {
                cout << "-1\n";
                return;
            }
            while (c[i] > 1) {
                ++res;
                --c[i];
                if (i+1 < q) --c[i+1];
            }
        }
        cout << res << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}