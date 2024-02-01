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

    vvi goodmasks(20);
    FOR(n, 1, 20) {
        FOR(mask, 1, 1<<n) {
            vi active(n);
            FOR(d, 0, n) if (mask>>d&1) {
                for (int u = d; u < n; u += d+1) active[u] ^= 1;
            }
            if (accumulate(active.begin(), active.end(), 0) <= n/5) goodmasks[n].push_back(mask);
        }
    }

    auto solve = [&]() {
        int n, m;
        cin >> n >> m;
        vector<pii> conds;
        FOR(i, 0, m) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            conds.emplace_back(u, v);
        }

        if (n >= 20) {
            cout << n << ' ';
            FOR(i, 0, n) cout << i+1 << ' ';
            cout << '\n';
            return;
        }

        for (int mask : goodmasks[n]) {
            bool fail = false;
            for (pii pr : conds) {
                int u = pr.first, v = pr.second;
                if (mask>>u&1 && !(mask>>v&1)) {
                    fail = true;
                    break;
                }
            }
            if (fail) continue;

            vi res;
            FOR(d, 0, n) if (mask>>d&1) res.push_back(d+1);
            cout << res.size() << ' ';
            for (int i : res) cout << i << ' ';
            cout << '\n';
            return;
        }
        cout << "-1\n";
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}