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
    
    int n, m;
    cin >> n >> m;
    ++n;
    vi l(m), r(m), a(m);
    vector<vector<pii>> aidas(n);
    FOR(i, 0, m) {
        cin >> l[i] >> r[i] >> a[i];
        --l[i]; --r[i];
        aidas[l[i]].emplace_back(r[i], a[i]);
    }

    vi tree(2*n), lazy(n);
    auto app = [&](int x, int delta) {
        tree[x] += delta;
        if (x < n) lazy[x] += delta;
    };
    
    auto build = [&](int x) {
        while (x) {
            tree[x] = lazy[x] + max(tree[2*x], tree[2*x+1]);
            x /= 2;
        }
    };

    auto upd = [&](int l, int r, int delta) {
        l += n;
        r += n;
        int l0=l, r0=r;
        while (l <= r) {
            if (l&1) app(l++, delta);
            if (!(r&1)) app(r--, delta);
            l /= 2;
            r /= 2;
        }
        build(l0/2);
        build(r0/2);
    };

    ROF(i, n-1, -1) {
        upd(i, i, tree[1]);
        for (pii pr : aidas[i]) {
            int r = pr.first, a = pr.second;
            upd(i, r, a);
        }
    }
    cout << tree[1] << ' ';
}