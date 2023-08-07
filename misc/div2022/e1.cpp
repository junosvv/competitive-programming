#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    
    vi l(n), r(n);
    vector<vector<pii>> toadd(n+1);
    FOR(i, 0, n) {
        cin >> l[i] >> r[i];
        --l[i]; --r[i];
        toadd[l[i]].emplace_back(i, r[i]);
    }

    vi tree(2*n);
    auto query = [&](int l, int r) {
        l += n;
        r += n;
        int res = 0;
        while (l <= r) {
            if (l&1) res = max(res, tree[l++]);
            if (!(r&1)) res = max(res, tree[r--]);
            l /= 2;
            r /= 2; 
        }
        return res;
    };

    auto upd = [&](int x, int delta) {
        x += n;
        if (tree[x] < delta) {
            tree[x] = delta;
            x /= 2;
            while (x) {
                tree[x] = max(tree[2*x], tree[2*x+1]);
                x /= 2;
            }
        }
    };

    int succ = n-1;
    FOR(i, 0, n) {
        for (pii pr : toadd[i]) {
            int x, r;
            tie(x, r) = pr;
            upd(x, r);
        }
        int at = i+1;
        while (at <= succ) {
            int u = query(i, at);
            if (u < at) {
                cout << "No " << i+1 << ' ' << at+1;
                exit(0);
            }
            at = u + 1;
        }
        succ = min(succ, );
    }
}