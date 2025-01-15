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
    vi a(n);
    FOR(i, 0, n) cin >> a[i];

    vi tree(2*n);
    auto upd = [&](int x, int val) {
        x += n;
        tree[x] = val;
        x /= 2;
        while (x) {
            tree[x] = tree[2*x] + tree[2*x+1];
            x /= 2;
        }
    };

    auto query = [&](int l, int r) {
        l += n;
        r += n;
        int res = 0;
        while (l <= r) {
            if (l&1) res += tree[l++];
            if (!(r&1)) res += tree[r--];
            l /= 2;
            r /= 2;
        }
        return res;
    };
    
    vi last(m+1, -1);
    int res = 0;
    FOR(i, 0, n) {
        if (last[a[i]] == -1) res += m-1;
        else {
            upd(last[a[i]], 0);
            res += query(last[a[i]], n-1);
        }
        upd(i, 1);
        last[a[i]] = i;
    }
    cout << res << '\n';
}