#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

const int MOD = 1e9+7;
int powa(int base, int exp) {
    int res = 1;
    while (exp) {
        if (exp&1) res = (ll)res * base % MOD;
        base = (ll)base * base % MOD;
        exp /= 2;
    }
    return res;
};
#define inv(x) powa(x, MOD-2)

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    const int M = 1e5+2;
    int n;
    // n = 99999;
    cin >> n;
    vi a(n);
    vvi loc(M);
    FOR(i, 0, n) {
        // a[i] = rand() % 4 + 1;
        cin >> a[i];
        loc[a[i]].push_back(i);
    }
    vvi G(n);
    // FOR(i, 0, n/2) {
    //     G[i].push_back(2*i+1);
    //     G[i].push_back(2*i+2);
    //     G[2*i+1].push_back(i);
    //     G[2*i+2].push_back(i);
    // }
    FOR(i, 0, n-1) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int t = 1;
    vi tin(n), tout(n), dep(n);
    const int K = 18;
    vvi up(K, vi(n, -1));
    up[0][0] = 0;
    function<void(int)> dfs = [&](int u) {
        tin[u] = t++;
        for (int v : G[u]) if (up[0][v] == -1) {
            up[0][v] = u;
            dep[v] = 1 + dep[u];
            dfs(v);
        }
        tout[u] = t++;
    };
    dfs(0);

    FOR(k, 1, K) {
        FOR(u, 0, n) {
            up[k][u] = up[k-1][up[k-1][u]];
        }
    }

    auto lca = [&](int u, int v) {
        if (dep[u] > dep[v]) swap(u, v);
        int temp = dep[v] - dep[u];
        FOR(k, 0, K) if (temp>>k&1) {
            v = up[k][v];
        }
        // assert(dep[u] == dep[v]);
        if (u == v) return u;
        ROF(k, K-1, -1) {
            if (up[k][u] != up[k][v]) {
                u = up[k][u];
                v = up[k][v];
            }
        }
        return up[0][u];
    };

    vi tree(t, 1), tree_indv(t, 1);
    auto upd = [&](int x, int val) {
        tree_indv[x] = tree_indv[x] * val % MOD;
        while (x < t) {
            tree[x] = (ll)tree[x] * val % MOD;
            x += x&-x;
        }
    };
    auto prefq = [&](int x) {
        int res = 1;
        while (x) {
            res = (ll)res * tree[x] % MOD;
            x -= x&-x;
        }
        return res;
    };
    auto query = [&](int l, int r) {
        return (ll)prefq(r) * inv(prefq(l-1)) % MOD;
    };
    
    int q;
    cin >> q;
    vi u1(q), v1(q), u2(q), v2(q), w1(q), w2(q);
    FOR(qi, 0, q) {
        int _;
        // u1[qi] = rnd(1, n);
        // v1[qi] = rnd(1, n);
        // u2[qi] = rnd(1, n);
        // v2[qi] = rnd(1, n);
        cin >> u1[qi] >> v1[qi] >> u2[qi] >> v2[qi] >> _;
        --u1[qi]; --v1[qi]; --u2[qi]; --v2[qi];
        w1[qi] = lca(u1[qi], v1[qi]);
        w2[qi] = lca(u2[qi], v2[qi]);
    }
    // cout << "here1" << endl;

    int r = rnd(0, MOD-1e5-1);
    vi aa(n), aainv(n);
    FOR(i, 0, n) {
        aa[i] = (r + a[i]) % MOD;
        aainv[i] = inv(aa[i]);
    }
    
    vi newloc(q);
    vvi queries(M);
    FOR(qi, 0, q) queries[0].push_back(qi);
    for (int b=M; b>1;) {
        // cout << "step " << b << endl;
        tree.assign(2*t, 1);
        int nb = (b+1) >> 1;

        FOR(i, M-b, M-b+(b>>1)) {
            for (int u : loc[i]) {
                upd(tin[u], aa[u]);
                upd(tout[u], aainv[u]);
            }
        }

        // int ccntA = 0, ccntB = 0;
        ROF(l, M-b, -1) {
            for (int qi : queries[l]) {
                // ++ccntA;
                int xx = (ll)query(tin[w1[qi]], tin[u1[qi]]) * query(tin[w1[qi]], tin[v1[qi]]) % MOD * (l <= a[w1[qi]] && a[w1[qi]] < l+(b>>1) ? aainv[w1[qi]] : 1) % MOD;
                int yy = (ll)query(tin[w2[qi]], tin[u2[qi]]) * query(tin[w2[qi]], tin[v2[qi]]) % MOD * (l <= a[w2[qi]] && a[w2[qi]] < l+(b>>1) ? aainv[w2[qi]] : 1) % MOD;
                // cout << "at " << l << " to " << l+b/2-1 << " | query " << qi << ": " << xx << ' ' << yy << '\n';
                if (xx == yy) newloc[qi] += b>>1;
            }
            if (l == 0) break;

            for (int u : loc[l+(b>>1)-1]) {
                // ++ccntB;
                upd(tin[u], aainv[u]);
                upd(tout[u], aa[u]);
            }
            for (int u : loc[l-1]) {
                // ++ccntB;
                upd(tin[u], aa[u]);
                upd(tout[u], aainv[u]);
            }
        }
        queries.assign(M, {});
        FOR(qi, 0, q) queries[newloc[qi]].push_back(qi);
        // cout << "ccnt: " << ccntA << ' ' << ccntB << endl;

        // cout << "iteration " << b << '\n';
        // FOR(l, 0, M) if (!queries[l].empty()) {
        //     cout << l << " -> ";
        //     for (int qi : queries[l]) cout << qi << ", ";
        //     cout << '\n';
        // }
        // cout << "\n\n";

        b = nb;
    }
    // cout << "here2" << endl;

    vi res(q);
    FOR(l, 0, M) {
        for (int qi : queries[l]) {
            res[qi] = l;
        }
    }
    FOR(qi, 0, q) {
        if (res[qi] == M-1) cout << 0;
        else cout << "1 " << res[qi];
        cout << '\n';
    }
}