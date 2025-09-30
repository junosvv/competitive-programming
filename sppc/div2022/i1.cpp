#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> foods;
    map<string,int> mp;
    
    vvi g(2*n), ginv(2*n);
    FOR(i, 0, n) {
        string s, t;
        cin >> s >> t;
        mp[s] = 2*i;
        mp[t] = 2*i+1;
        foods.push_back(s);
        foods.push_back(t);
    }
    FOR(i, 0, m) {
        string s, t;
        cin >> s >> t;
        int u = mp[s], v = mp[t];
        g[u].push_back(v^1);
        g[v].push_back(u^1);
    }

    FOR(u, 0, 2*n) for (int v : g[u]) ginv[v].push_back(u);

    vi comp(2*n), tour;
    function<void(int)> dfs = [&](int u) {
        comp[u] = 1;
        for (int v : g[u]) if (!comp[v]) {
            dfs(v);
        }
        tour.push_back(u);
    };

    FOR(u, 0, 2*n) if (!comp[u]) {
        dfs(u);
    }

    comp.assign(2*n, -1);
    function<void(int, int)> dfs2 = [&](int u, int c) {
        comp[u] = c;
        for (int v : ginv[u]) if (comp[v] == -1) {
            dfs2(v, c);
        }
    };

    int compnum = 0;
    ROF(u, 2*n-1, -1) if (comp[tour[u]] == -1) {
        dfs2(tour[u], compnum);
        ++compnum;
    }

    bool fail = false;
    vector<string> res;
    FOR(u, 0, n) {
        if (comp[u<<1] == comp[u<<1^1]) {
            fail = true;
            break;
        }
        if (comp[u<<1] > comp[u<<1^1]) {
            res.push_back(foods[u<<1]);
        } else {
            res.push_back(foods[u<<1^1]);
        }
    }

    if (fail) cout << "No";
    else {
        cout << "Yes\n";
        for (string s : res) cout << s << '\n';
    }
}