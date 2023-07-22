#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define inv(x) powa(x, MOD-2)
const int MOD = 998244353;
 
int powa(int base, int exp) {
    int res = 1;
    while (exp) {
        if (exp&1) res = res * base % MOD;
        base = base * base % MOD;
        exp /= 2;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, k;
    cin >> n >> k;
    vi nxt(n), b(n);
    vvi GT(n);
    FOR(i, 0, n) {
        cin >> nxt[i];
        --nxt[i];
        GT[nxt[i]].push_back(i);
    }
    FOR(i, 0, n) cin >> b[i];

    vi cycle(n, -2), dist(n), stack;
    vvi who(n), whodist(n);
    function<void(int)> dfs = [&](int u) {
        cycle[u] = -1;
        stack.push_back(u);
        if (cycle[nxt[u]] == -2) {
            dfs(nxt[u]);
            if (cycle[u] != -1) return;
        } else if (cycle[nxt[u]] == -1) {
            while (!stack.empty()) {
                int v = stack.back();
                stack.pop_back();
                cycle[v] = v;
                if (v == nxt[u]) return;
            }
        }
        cycle[u] = cycle[nxt[u]];
        dist[u] = 1 + dist[nxt[u]];
        who[cycle[u]].push_back(u);
        whodist[dist[u]].push_back(u);
    };
    FOR(u, 0, n) if (cycle[u] == -2) {
        stack.clear();
        dfs(u);
    }

    vi seen(n), res(n);
    function<void(int)> dfs2 = [&](int u) {
        seen[u] = true;
        if (dist[u] >= 2) {
            res[nxt[u]] = (res[nxt[u]] + b[u]) % MOD;
            int m = stack.size();
            if (m-1-k >= 0 && dist[stack[m-1-k]]) {
                res[stack[m-1-k]] = (res[stack[m-1-k]] + MOD - b[u]) % MOD;
            }
        }
        for (int v : GT[u]) if (!seen[v]) {
            stack.push_back(u);
            dfs2(v);
            stack.pop_back();
        }
    };
    FOR(u, 0, n) if (!seen[cycle[u]]) {
        stack.clear();
        dfs2(cycle[u]);
    }

    ROF(d, n-1, 1) for (int u : whodist[d]) {
        res[nxt[u]] = (res[nxt[u]] + res[u]) % MOD;
    }

    function<void(int)> dfs3 = [&](int u) {
        seen[u] = true;
        stack.push_back(u);
        if (!seen[nxt[u]]) dfs3(nxt[u]);
    };
    seen.assign(n, false);
    FOR(u, 0, n) if (!seen[cycle[u]]) {
        stack.clear();
        dfs3(cycle[u]);
        int m = stack.size();
        FOR(i, 0, m) {
            res[stack[0]] = (res[stack[0]] + k/m % MOD * b[stack[i]]) % MOD;
            if (k%m) {
                int l = (i+1) % m, r = l + k%m - 1;
                res[stack[l]] = (res[stack[l]] + b[stack[i]]) % MOD;
                if (r >= m) {
                    res[stack[0]] = (res[stack[0]] + b[stack[i]]) % MOD;
                    r -= m;
                }
                if (r+1 < m) res[stack[r+1]] = (res[stack[r+1]] + MOD - b[stack[i]]) % MOD;
            }
            for (int v : who[stack[i]]) if (dist[v] <= k) {
                res[stack[0]] = (res[stack[0]] + (k-dist[v]+1)/m % MOD * b[v]) % MOD;
                int r = i + (k-dist[v]+1)%m - 1;
                if (r < i) continue;
                res[stack[i]] = (res[stack[i]] + b[v]) % MOD;
                if (r >= m) {
                    res[stack[0]] = (res[stack[0]] + b[v]) % MOD;
                    r -= m;
                }
                if (r+1 < m) res[stack[r+1]] = (res[stack[r+1]] + MOD - b[v]) % MOD;
            }
        }
        FOR(i, 1, m) res[stack[i]] = (res[stack[i]] + res[stack[i-1]]) % MOD;
    }

    FOR(u, 0, n) cout << res[u] * inv(k%MOD) % MOD << ' ';
}