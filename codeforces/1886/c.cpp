#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define SQ(x) (x)*(x)


signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    auto solve = [&]() {
        string s;
        cin >> s;
        int n = s.size();
        int k;
        cin >> k;
        int upp = 0;
        FOR(d, 0, n) {
            int d0 = d;
            upp += n-d;
            if (k <= upp) {
                string t;
                FOR(i, 0, n) {
                    while (d && !t.empty() && t.back() > s[i]) {
                        t.pop_back();
                        --d;
                    }
                    t += s[i];
                }
                upp += -n + 1 + d0;
                cout << t[k-upp];
                return;
            }
        }
        assert(false);
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}