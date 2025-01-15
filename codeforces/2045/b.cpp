#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, d, s;
    cin >> n >> d >> s;
    n = n/s*s;
    d = d/s*s;

    int res = s;
    if (2*d <= n) res = max(res, 2*d);
    else {
        if (n-s <= d) res = max(res, n);
        FOR(q, 2, 1e6+1) if ((n/s)%q == 0 && n-n/q <= d) {
            res = max(res, n);
        }
        res = max(res, n-s);
    }
    cout << res;
}