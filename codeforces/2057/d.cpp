#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define pii pair<int,int>
#define mii map<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    auto solve = [&]() {
        int n, q;
        cin >> n >> q;
        vi a(n);
        FOR(i, 0, n) cin >> a[i];
        int n0 = n;
        n = 1;
        while (n < n0) n *= 2;

        const int INF = 1e15;
        vi mintree0(2*n, INF), mintree1(2*n, INF), maxtree0(2*n, -INF), maxtree1(2*n, -INF), anstree0(2*n), anstree1(2*n);
        auto upd = [&](int x, int val) {
            a[x] = val;
            mintree0[x+n] = a[x] + x;
            maxtree0[x+n] = a[x] + x;
            mintree1[x+n] = a[x] - x;
            maxtree1[x+n] = a[x] - x;
            x += n;
            x /= 2;
            while (x) {
                mintree0[x] = min(mintree0[2*x], mintree0[2*x+1]);
                mintree1[x] = min(mintree1[2*x], mintree1[2*x+1]);
                maxtree0[x] = max(maxtree0[2*x], maxtree0[2*x+1]);
                maxtree1[x] = max(maxtree1[2*x], maxtree1[2*x+1]);
                anstree0[x] = max(anstree0[2*x], max(anstree0[2*x+1], maxtree0[2*x] - mintree0[2*x+1]));
                anstree1[x] = max(anstree1[2*x], max(anstree1[2*x+1], maxtree1[2*x+1] - mintree1[2*x]));
                x /= 2;
            }
        };
        
        FOR(i, 0, n0) upd(i, a[i]);
        cout << max(anstree0[1], anstree1[1]) << ' ';
        FOR(qi, 0, q) {
            int i, x;
            cin >> i >> x;
            --i;
            upd(i, x);
            cout << max(anstree0[1], anstree1[1]) << ' ';
        }
        cout << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}