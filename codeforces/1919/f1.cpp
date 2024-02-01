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

    int n, q;
    cin >> n >> q;
    vi a(n), b(n), c(n-1);
    FOR(i, 0, n) cin >> a[i];
    FOR(i, 0, n) cin >> b[i];
    FOR(i, 0, n-1) cin >> c[i];
    
    int sumnegs = accumulate(b.begin(), b.end(), 0LL);
    int sz = 2*n+1;
    vi tree(2*sz), lazy(sz);
    auto apply = [&](int x, int delta) {
        tree[x] += delta;
        if (x < sz) lazy[x] += delta;
    };
    auto build = [&](int x) {
        while (x) {
            tree[x] = min(tree[2*x], tree[2*x+1]) + lazy[x];
            x /= 2;
        }
    };
    // auto push = [&](int x) {
    //     ROF(d, 22, 0) {
    //         int u = x >> d;
    //         apply(2*u, lazy[u]);
    //         apply(2*u+1, lazy[u]);
    //         lazy[u] = 0;
    //     }
    // };
    auto upd = [&](int l, int r, int delta) {
        l += sz;
        r += sz;
        int l0 = l, r0 = r;
        while (l <= r) {
            if (l&1) apply(l++, delta);
            if (!(r&1)) apply(r--, delta);
            l /= 2;
            r /= 2;
        }
        build(l0/2);
        build(r0/2);
    };
    auto query = [&]() {
        return tree[1];
    };

    FOR(i, 0, n) tree[sz+1+2*i] = a[i];
    FOR(i, 0, n) tree[sz+2+2*i] = -b[i];
    FOR(i, 1, sz) tree[sz+i] += tree[sz+i-1];
    ROF(i, sz-1, 0) tree[i] = min(tree[2*i], tree[2*i+1]);
    
    FOR(qi, 0, q) {
        int i, x, y, z;
        cin >> i >> x >> y >> z;
        --i;
        upd(2*i+1, sz-1, x-a[i]);
        upd(2*i+2, sz-1, b[i]-y);
        sumnegs += y - b[i];
        a[i] = x;
        b[i] = y;
        // cout << sumnegs << " + " << tree[1] << " = " << sumnegs + tree[1] << '\n';
        cout << sumnegs + tree[1] << '\n';
    }
}