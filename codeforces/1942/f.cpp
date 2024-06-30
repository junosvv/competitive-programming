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

    const int B = 7;

    int n, q;
    cin >> n >> q;
    int m = 1;
    while (B*m < n) m *= 2;
    vi a(B*m);
    FOR(i, B*m-n, B*m) cin >> a[i];

    vi tree(2*m), c(2*m);
    auto build = [&](int x) {
        tree[m+x] = 0;
        FOR(i, 0, B) {
            tree[m+x] = sqrtl(tree[m+x] + a[B*x+i]);
        }
        c[m+x] = tree[m+x] + 1;
        ROF(i, B-1, -1) {
            if (c[m+x] >= 2e9) {
                c[m+x] = 4e18;
                break;
            }
            c[m+x] *= c[m+x];
            c[m+x] -= a[B*x+i];
        }
    };

    FOR(x, 0, m) build(x);

    auto merge = [&](int x) {
        tree[x] = tree[2*x+1] + (tree[2*x] >= c[2*x+1]);
        c[x] = c[2*x+1] == tree[2*x] + 1 ? c[2*x] : 4e18;
    };

    ROF(x, m-1, 0) merge(x);

    FOR(qi, 0, q) {
        int k, v;
        cin >> k >> v;
        --k;
        a[B*m-n+k] = v;

        int x = (B*m-n+k) / B;
        build(x);
        x += m;
        x /= 2;
        while (x) {
            merge(x);
            x /= 2;
        }
        cout << tree[1] << '\n';
    }
}