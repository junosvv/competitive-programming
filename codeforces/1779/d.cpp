#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define pii pair<int,int>
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vi a(n), b(n);
        FOR(i, 0, n) cin >> a[i];
        vector<pii> prs;
        FOR(i, 0, n) {
            cin >> b[i];
            prs.emplace_back(-b[i], i);
        }
        sort(prs.begin(), prs.end());
        int m;
        cin >> m;
        map<int,int> razors;
        FOR(i, 0, m) {
            int x;
            cin >> x;
            if (!razors.count(x)) razors[x] = 0;
            ++razors[x];
        }
 
        vi tree(2*n);
        FOR(i, 0, n) tree[n+i] = b[i];
        ROF(i, n-1, 0) tree[i] = max(tree[2*i], tree[2*i+1]);
 
        auto query = [&](int l, int r) {
            l += n;
            r += n;
            int res = 0;
            while (l <= r) {
                if (l&1LL) res = max(res, tree[l++]);
                if (!(r&1LL)) res = max(res, tree[r--]);
                l >>= 1;
                r >>= 1;
            }
            return res;
        };
 
        int lx;
        bool first = true;
        bool fail = false;
        for (pii pr : prs) {
            int i = pr.second;
            if (b[i] > a[i]) {
                fail = true;
                break;
            }
            if (b[i] != a[i]) {
                if (first || b[i] != b[lx] || query(lx, i) > b[i]) {
                    if (!razors[b[i]]) {
                        fail = true;
                        break;
                    }
                    --razors[b[i]];
                    first = false;
                    lx = i;
                }
            }
        }
 
        if (fail) cout << "NO\n";
        else cout << "YES\n";
    }
}