#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

signed main() {
    // ios::sync_with_stdio(0), cin.tie(0);

    auto solve = [&]() {
        int n;
        cin >> n;
        vi a(n+1);
        int pos = 0, neg = 0;
        FOR(i, 1, n+1) {
            cin >> a[i];
            if (a[i] > 0) ++pos;
            if (a[i] < 0) ++neg;
        }
        int m = min_element(a.begin()+1, a.end()) - a.begin();
        int M = max_element(a.begin()+1, a.end()) - a.begin();

        vector<pii> res;
        if (neg <= 7) {
            FOR(_, 0, 5) res.emplace_back(M, M);
            a[M] *= 32;
        } else if (pos <= 7) {
            FOR(_, 0, 5) res.emplace_back(m, m);
            a[m] *= 32;
        }
        m = min_element(a.begin()+1, a.end()) - a.begin();
        M = max_element(a.begin()+1, a.end()) - a.begin();
        
        if (abs(a[M]) >= abs(a[m])) {
            FOR(i, 1, n+1) if (a[i] < 0) {
                res.emplace_back(i, M);
                a[i] += a[M];
            }
        } else {
            FOR(i, 1, n+1) if (a[i] > 0) {
                res.emplace_back(i, m);
                a[i] += a[m];
            }
        }

        if (*min_element(a.begin(), a.end()) >= 0) {
            FOR(i, 2, n+1) res.emplace_back(i, i-1);
        } else {
            assert(*max_element(a.begin(), a.end()) <= 0);
            ROF(i, n-1, 0) res.emplace_back(i, i+1);
        }

        cout << res.size() << '\n';
        for (pii pr : res) cout << pr.first << ' ' << pr.second << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}