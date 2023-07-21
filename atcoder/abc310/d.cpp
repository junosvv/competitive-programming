#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, t, m;
    cin >> n >> t >> m;

    vvi bads(n);
    FOR(i, 0, m) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        bads[b].push_back(a);
    }

    int res = 0;
    vvi part(t);
    part[0] = {0};
    int empties = t-1;
    function<void(int)> dfs = [&](int upto) {
        if (empties > n-upto) return;
        if (upto == n) {
            ++res;
            return;
        }
        FOR(ti, 0, t) {
            bool fail = false;
            for (int u : part[ti]) for (int v : bads[upto]) if (u == v) fail = true;
            if (fail) continue;
            if (part[ti].empty()) --empties;
            part[ti].push_back(upto);
            dfs(upto+1);
            part[ti].pop_back();
            if (part[ti].empty()) ++empties;
        }
    };

    dfs(1);
    FOR(i, 2, t) res /= i;
    cout << res;
}