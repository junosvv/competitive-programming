#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;
    vi a(n);
    FOR(i, 0, n) cin >> a[i];
    vi s(m), f(m), c(m), r(m);
    FOR(i, 0, m) {
        cin >> s[i] >> f[i] >> c[i] >> r[i];
        --s[i]; --f[i];
    }

    auto check = [&](int i, int V) {
        int fuel = V;
        int topups = r[i];
        FOR(j, s[i]+1, f[i]+1) {
            if (a[j] - a[j-1] > V) return false;
            fuel -= a[j] - a[j-1];
            if (fuel < 0) {
                fuel = V - (a[j] - a[j-1]);
                --topups;
                if (topups < 0) return false;
            }
        }
        return true;
    };

    vi perm(m);
    FOR(i, 0, m) perm[i] = i;
    random_shuffle(perm.begin(), perm.end());
    
    int res = 0;
    FOR(ii, 0, m) {
        int i = perm[ii];
        if (check(i, res/c[i])) continue;
        int V = 1e9;
        for (int b=1e9; b>=1; b/=2) {
            while (V-b > 0 && check(i, V-b)) V -= b;
        }
        V *= c[i];
        res = max(res, V);
    }
    cout << res;
}