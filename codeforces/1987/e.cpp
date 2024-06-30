#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define t3i tuple<int,int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    auto solve = [&]() {
        int n;
        cin >> n;
        vi a(n);
        FOR(i, 0, n) cin >> a[i];
        vi par(n);
        vvi G(n);
        FOR(i, 1, n) {
            cin >> par[i];
            --par[i];
            G[par[i]].push_back(i);
        }

        int res = 0;
        vector<t3i> tups;
        function<void(int)> calc = [&](int u) {
            int sm = 0;
            for (int v : G[u]) {
                calc(v);
                sm += a[v];
            }

            if (!G[u].empty() && a[u] > sm) {
                int k = a[u] - sm;
                // cout << "resolving " << u+1 << " by " << k << '\n';
                vi b(n);

                vector<t3i> q;
                q.emplace_back(u, 0, 0);
                int qi = 0;
                while (qi < q.size()) {
                    int v, dep, _;
                    tie(v, dep, _) = q[qi];

                    for (int w : G[v]) {
                        if (G[w].empty()) q.emplace_back(w, dep+1, 1e15);
                        else {
                            int sm = 0;
                            for (int x : G[w]) sm += a[x];
                            q.emplace_back(w, dep+1, sm-a[w]);
                        }
                    }
                    ++qi;
                }

                for (t3i tup : q) {
                    int v, dep, pot;
                    tie(v, dep, pot) = tup;

                    int cur = min(k, pot);
                    k -= cur;
                    b[v] += cur;
                    // cout << "seeing " << v+1 << " has pot " << pot << ". Adding " << cur << " * " << dep << " to res.\n";
                    res += cur * dep;
                    if (k == 0) break;
                }

                reverse(q.begin(), q.end());
                for (t3i tup : q) {
                    int v = get<0>(tup);
                    for (int w : G[v]) b[v] += b[w];
                    if (v != u) a[v] += b[v];
                }

                // cout << "Now: ";
                // for (int i : a) cout << i << ' ';
                // cout << '\n';
            }
        };

        calc(0);
        cout << res << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}