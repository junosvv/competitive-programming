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
#define t3i tuple<int,int,int>
#define mii map<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    auto solve = [&]() {
        int n;
        cin >> n;
        vi w(n);
        FOR(i, 0, n) cin >> w[i];
        vvi G(n);
        FOR(i, 0, n-1) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        
        vector<t3i> events;
        vi depth(n), tin(n), tout(n);
        int t = 0;
        function<void(int,int)> dfs = [&](int u, int p) {
            tin[u] = t++;
            events.emplace_back(w[u], depth[u], u);
            for (int v : G[u]) if (v != p) {
                depth[v] = 1 + depth[u];
                dfs(v, u);
            }
            tout[u] = t++;
        };
        dfs(0, 0);

        auto isanc = [&](int u, int v) {
            return tin[u] <= tin[v] && tout[v] <= tout[u];
        };

        sort(events.rbegin(), events.rend());
        int ll = 1e9, rr = -1e9, prevw = 1e9, prevll = 1e9, prevrr = -1e9;
        for (t3i tup : events) {
            int u = get<2>(tup);
            if (w[u] != prevw) {
                prevll = ll;
                prevrr = rr;
            }
            if (!(tin[u] <= prevll && prevrr <= tout[u])) {
                cout << u+1 << '\n';
                return;
            }
            ll = min(ll, tin[u]);
            rr = max(rr, tout[u]);
            prevw = w[u];
        }
        cout << "0\n";
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}