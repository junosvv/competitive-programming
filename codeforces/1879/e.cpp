#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

const int MOD = 998244353;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    vi par(n);
    vvi G(n);
    FOR(i, 1, n) {
        cin >> par[i];
        --par[i];
        G[par[i]].push_back(i);
    }

    auto solve = [&](auto func) {
        while (true) {
            int x;
            cin >> x;
            if (x) break;
            cout << func() << endl;
        }
        exit(0);
    };
    
    if (G[0].size() == n-1) {
        cout << 1 << '\n';
        FOR(i, 0, n-1) cout << 1 << ' ';
        cout << endl;
        auto one = [&]() {
            int _;
            cin >> _;
            return 1;
        };
        solve(one);
    }

    vi iro(n);
    function<bool(int)> dfs = [&](int u) {
        if (G[u].size() == 1 && iro[u] == 2) return false;
        for (int v : G[u]) {
            iro[v] = iro[u]%2 + 1;
            if (!dfs(v)) return false;
        }
        return true;
    };

    for (int s : G[0]) {
        iro[s] = 1;
        if (dfs(s)) continue;
        iro[s] = 2;
        if (dfs(s)) continue;
        cout << 3 << '\n';
        FOR(u, 1, n) {
            iro[u] = iro[par[u]] % 3 + 1;
            cout << iro[u] << ' ';
        }
        cout << endl;

        auto three = [&]() {
            int a, b, c;
            cin >> a >> b >> c;
            if (a && b) return 1;
            if (b && c) return 2;
            if (a && c) return 3;
            if (a) return 1;
            if (b) return 2;
            return 3;
        };

        solve(three);
    }

    cout << 2 << '\n';
    FOR(u, 1, n) cout << iro[u] << ' ';
    cout << endl;

    auto two = [&]() {
        int a, b;
        cin >> a >> b;
        if (a == 1) return 1;
        return 2;
    };

    solve(two);
}