#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    auto depth = [&](int n) {
        int res = 0;
        while (n > 1) {
            ++res;
            n >>= 1;
        }
        return res;
    };

    vi p2(63, 1);
    FOR(i, 1, 63) p2[i] = 2 * p2[i-1];

    auto query = [&](int l, int r) {
        if (l > r) return 0LL;
        assert(l >= 0);
        return p2[r+1] - p2[l];
    };

    int T;
    cin >> T;
    FOR(ti, 0, T) {
        int n, x, k;
        cin >> n >> x >> k;
        
        int dx = depth(x);
        int dn = depth(n);
        int lgth = min(k-1, dx);
        
        int res = 0;
        int cur = 0;
        for (int b = lgth; b>=1; b/=2) {
            while (cur+b <= lgth && dx+k-2*cur >= dn) cur += b;
        }
        res += query(k-1-lgth, k-2-cur);
        if (dx+k-2*cur == dn) {
            int l = dx - cur + 1;
            int nn = n >> l;
            int xx = x >> (dx-(k-1-cur));
            if (nn / 2 == xx / 2 && nn != xx) {
                int M = (nn+1) * (1LL<<l) - 1;
                res += (1LL << l) - (M-n);
            } else {
                res += 1LL << l;
            }
        }
        if (dx+k < dn) res += p2[k];
        else if (dx+k == dn) {
            int m = x * (1LL<<k);
            int M = (x+1) * (1LL<<k) - 1;
            if (m <= n && n <= M) {
                res += (1LL << k) - (M-n);
            } else res += 1LL << k;
        }
        cout << res << '\n';
    }
}