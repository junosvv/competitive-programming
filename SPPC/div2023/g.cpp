#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vs vector<string>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int k, k2;
    cin >> k >> k2;
    k -= k2;
    vector<string> strings;
    map<string, int> stringcode;

    auto ins = [&](string s) {
        if (!stringcode.count(s)) {
            stringcode[s] = strings.size();
            strings.push_back(s);
        }
    };

    vvi G;
    vi bal;
    FOR(i, 0, k) {
        string s, t;
        cin >> s >> t;
        ins(s);
        ins(t);
        int u = stringcode[s];
        int v = stringcode[t];
        while (u >= G.size() || v >= G.size()) {
            G.push_back(vi());
            bal.push_back(0);
        }
        G[u].push_back(v);
        ++bal[u];
        --bal[v];
    }

    int n = G.size();
    int start = 0;
    FOR(u, 0, n) if (bal[u] >= 1) start = u;

    vi path;
    function<void(int)> dfs = [&](int u) {
        while (!G[u].empty()) {
            int v = G[u].back();
            G[u].pop_back();
            dfs(v);
        }
        path.push_back(u);
    };
    
    dfs(start);
    reverse(path.begin(), path.end());
    cout << strings[path[0]];
    FOR(i, 1, path.size()) cout << strings[path[i]].back();
}