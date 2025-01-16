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

    int R, C;
    cin >> R >> C;

    auto up = [&](int r, int c) {
        return r*C + c;
    };
    
    auto down = [&](int r, int c) {
        return (r+1)*C + c;
    };

    auto left = [&](int r, int c) {
        return (R+1)*C + r*(C+1) + c;
    };

    auto right = [&](int r, int c) {
        return (R+1)*C + r*(C+1) + c+1;
    };

    vvi G((R+1)*C + R*(C+1));
    map<pii,pii> m;
    int mirrors = 0;
    FOR(row, 0, R) FOR(col, 0, C) {
        int u = up(row, col), d = down(row, col), l = left(row, col), r = right(row, col);
        char x;
        cin >> x;
        if (x == '.') {
            G[l].push_back(r);
            G[r].push_back(l);
            G[u].push_back(d);
            G[d].push_back(u);
        } else if (x == '/') {
            G[l].push_back(u);
            G[u].push_back(l);
            G[r].push_back(d);
            G[d].push_back(r);
            m[{l, u}] = {row, col};
            m[{u, l}] = {row, col};
            m[{r, d}] = {row, col};
            m[{d, r}] = {row, col};
            ++mirrors;
        } else {
            G[l].push_back(d);
            G[d].push_back(l);
            G[r].push_back(u);
            G[u].push_back(r);
            m[{l, d}] = {row, col};
            m[{d, l}] = {row, col};
            m[{r, u}] = {row, col};
            m[{u, r}] = {row, col};
            ++mirrors;
        }
    }
    
    vvi mark(R, vi(C));
    int nmark = 0;
    vector<pii> upds;
    function<void(int,int)> dfs = [&](int u, int p) {
        for (int v : G[u]) if (v != p) {
            if (m.count({u, v})) {
                int r, c;
                tie(r, c) = m[{u, v}];
                if (!mark[r][c]) {
                    mark[r][c] = 1;
                    ++nmark;
                    upds.emplace_back(r, c);
                }
            }
            dfs(v, u);
        }
    };

    vector<string> res;
    FOR(c, 0, C) {
        dfs(up(0, c), -1);
        if (nmark == mirrors) res.push_back("N" + to_string(c+1));
        for (pii pr : upds) {
            mark[pr.first][pr.second] = 0;
            --nmark;
        }
        upds.clear();
        
        dfs(down(R-1, c), -1);
        if (nmark == mirrors) res.push_back("S" + to_string(c+1));
        for (pii pr : upds) {
            mark[pr.first][pr.second] = 0;
            --nmark;
        }
        upds.clear();
    }

    FOR(r, 0, R) {
        dfs(left(r, 0), -1);
        if (nmark == mirrors) res.push_back("W" + to_string(r+1));
        for (pii pr : upds) {
            mark[pr.first][pr.second] = 0;
            --nmark;
        }
        upds.clear();
        
        dfs(right(r, C-1), -1);
        if (nmark == mirrors) res.push_back("E" + to_string(r+1));
        for (pii pr : upds) {
            mark[pr.first][pr.second] = 0;
            --nmark;
        }
        upds.clear();
    }

    cout << res.size() << '\n';
    for (string s : res) cout << s << ' ';
}