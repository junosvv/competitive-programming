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
    string s;
    cin >> n >> m >> s;
    m += n;
    vector<pair<int, char>> updates(m);
    FOR(i, 0, n) {
        updates[i].first = i;
        updates[i].second = s[i];
    }
    FOR(i, n, m) {
        cin >> updates[i].first >> updates[i].second;
        --updates[i].first;
    }
    vvi buckets(n);
    FOR(i, 0, m) buckets[updates[i].first].push_back(i);
    
    // FOR(i, 0, n) {
    //     cout << i << ": ";
    //     for (int j : buckets[i]) cout << j << ' ';
    //     cout << '\n';
    // }

    vi prev(m, -1), last(n);
    FOR(i, 0, m) {
        if (updates[i].first >= 1) prev[i] = last[updates[i].first - 1];
        last[updates[i].first] = i;
    }

    // cout << "prev: ";
    // FOR(i, n, m) cout << prev[i] << ' ';
    // cout << '\n';

    vvi trie(1, vi(26));
    vvi sols(1);
    vi mynode(m);

    FOR(i, 0, n) {
        for (int j : buckets[i]) {
            cout << "proc " << updates[j].first+1 << ' ' << updates[j].second << " prev: " << prev[j] << '\n';
            int u = prev[j] >= 0 ? mynode[prev[j]] : 0;
            int c = updates[j].second - 'a';
            if (trie[u][c] == 0) {
                cout << "    adding " << trie.size() << " to " << u << ' ' << (char)('a'+c) << '\n';
                trie[u][c] = trie.size();
                trie.push_back(vi(26));
                sols.emplace_back();
            }
            mynode[j] = trie[u][c];
            sols[mynode[j]].push_back(j);
        }
    }
    
    // FOR(i, 0, sols.size()) {
    //     cout << i << ": ";
    //     for (int j : sols[i]) cout << j << ' ';
    //     cout << '\n';
    // }

    function<void(int)> dfs = [&](int u) {
        FOR(c, 0, 26) if (trie[u][c]) {
            dfs(v);
        }
    };
}