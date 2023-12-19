#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define SQ(x) (x)*(x)

void maxi(int& a, int b) {
    a = max(a, b);
}
void mini(int& a, int b) {
    a = min(a, b);
}

const int MOD = 1e9+7;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    vi h(n), a(n);
    FOR(i, 0, n) {
        cin >> h[i];
        --h[i];
    }
    FOR(i, 0, n) cin >> a[i];

    vi tree(2*n);
    auto upd = [&](int x, int val) {
        x += n;
        tree[x] = val;
        x /= 2;
        while (x) {
            tree[x] = max(tree[2*x], tree[2*x+1]);
            x /= 2;
        }
    };

    auto query = [&](int l, int r) {
        int res = 0;
        l += n;
        r += n;
        while (l <= r) {
            if (l&1) maxi(res, tree[l++]);
            if (!(r&1)) maxi(res, tree[r--]);
            l /= 2;
            r /= 2;
        }
        return res;
    };

    FOR(i, 0, n) {
        upd(h[i], a[i] + query(0, h[i]-1));
    }
    cout << query(0, n-1);
}