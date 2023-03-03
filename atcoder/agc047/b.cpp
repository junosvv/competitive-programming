#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vs vector<string>
#define vb vector<bool>

vector<vi> trie;
vb starred;
vector<vi> dp;
void dfs(int c, int u) {
    FOR(j, 0, 26) if (trie[u][j] != 0) {
        int v = trie[u][j];
        dfs(c, v);
        if (j == c) dp[c][v] = 0;
        if (starred[v]) ++dp[c][v];
        if (j != c) dp[c][u] += dp[c][v];
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vs strings(n);
    FOR(i, 0, n) {
        cin >> strings[i];
        reverse(strings[i].begin(), strings[i].end());
    }

    trie.assign(1, vi(26));
    starred = {false};
    vi stars(n), par(n);
    FOR(i, 0, n) {
        int u = 0;
        for (char j : strings[i]) {
            if (trie[u][j-'a'] == 0) {
                trie[u][j-'a'] = trie.size();
                trie.push_back(vi(26));
                starred.push_back(false);
            }
            par[i] = u;
            u = trie[u][j-'a'];
        }
        starred[u] = true;
        stars[i] = u;
    }

    int m = trie.size();
    dp.assign(27, vi(m));
    FOR(c, 0, 27) dfs(c, 0);

    int res = 0;
    FOR(i, 0, n) {
        int u = stars[i];
        res += dp[26][par[i]] - dp[strings[i].back()-'a'][par[i]] - 1;
    }
    
    cout << res;
}
