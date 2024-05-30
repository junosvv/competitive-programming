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

    auto pf = [&](int x) {
        vi facts;
        for (int d=2; d*d<=x; ++d) {
            while (x%d == 0) {
                facts.push_back(d);
                x /= d;
            }
        }
        if (x > 1) facts.push_back(x);
        return facts;
    };

    auto solve = [&]() {
        int n;
        cin >> n;
        vi a(n);
        FOR(i, 0, n) cin >> a[i];

        multiset<int> factset;
        FOR(i, 0, n) {
            int prev = -1;
            vi cur;
            for (int d : pf(a[i])) {
                if (d != prev) {
                    while (cur.size() > factset.count(prev)) {
                        factset.insert(prev);
                    }
                    cur.clear();
                }
                cur.push_back(d);
                prev = d;
            }
            while (cur.size() > factset.count(prev)) {
                factset.insert(prev);
            }
        }
        vi facts;
        for (int i : factset) facts.push_back(i);
        int f = facts.size();

        // cout << "facts: ";
        // for (int i : facts) cout << i << ' ';
        // cout << '\n';

        int prod = 1;
        int mx = *max_element(a.begin(), a.end());
        for (int i : facts) {
            prod *= i;
            if (prod > mx) {
                cout << n << '\n';
                return;
            }
        }

        int res = 0;
        FOR(mask, 1, 1LL<<f) {
            int prod = 1;
            FOR(i, 0, f) if (mask>>i&1LL) prod *= facts[i];
            bool fail = false;
            FOR(i, 0, n) if (a[i] == prod) fail = true;
            if (fail) continue;

            int cnt = 0;
            FOR(i, 0, n) if (prod % a[i] == 0) ++cnt;
            res = max(res, cnt);
        }
        cout << res << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}