#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    vi a(n), f;
    map<int,int> finv;
    FOR(i, 0, n) {
        cin >> a[i];
        if (!finv.count(a[i])) {
            finv[a[i]] = 1;
            f.push_back(a[i]);
        }
    }
    sort(f.begin(), f.end());
    int m = f.size();
    FOR(i, 0, m) finv[f[i]] = i;
    FOR(i, 0, n) a[i] = finv[a[i]];
    
    vi tree(2*m);
    auto query = [&](int l, int r) {
        l += m;
        r += m;
        int res = 0;
        while (l <= r) {
            if (l&1) res += tree[l++];
            if (!(r&1)) res += tree[r--];
            l /= 2;
            r /= 2;
        }
        return res;
    };

    auto upd = [&](int x, int delta) {
        x += m;
        while (x) {
            tree[x] += delta;
            x /= 2;
        }
    };

    vi b(n);
    FOR(i, 0, n) {
        b[i] = query(a[i]+1, m-1);
        upd(a[i], 1);
    }

    int k = *max_element(b.begin(), b.end());
    cout << k << '\n';
    if (k) {
        vi res(k);
        FOR(i, 0, n) {
            ++res[0];
            if (b[i] < k) --res[b[i]];
        }
        FOR(i, 1, k) res[i] += res[i-1];
        FOR(i, 0, k) cout << res[i] << '\n';
    }
}