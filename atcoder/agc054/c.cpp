#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define vi vector<int>
#define vvi vector<vi>
 
const int MOD = 998244353;
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
 
    int n, k;
    cin >> n >> k;
    vi a(n);
    FOR(i, 0, n) {
        cin >> a[i];
        --a[i];
    }

    vi tree(2*n);
    auto upd = [&](int x, int delta) {
        x += n;
        while (x) {
            tree[x] += delta;
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

    int res = 1;
    FOR(i, 0, n) {
        if (query(a[i]+1, n-1) == k) {
            res *= n-i;
            res %= MOD;
        }
        upd(a[i], 1);
    }
    cout << res;
}