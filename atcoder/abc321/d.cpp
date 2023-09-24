#include <bits/stdc++.h>
using namespace std;

typedef long long lg;
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    lg n, m, p;
    cin >> n >> m >> p;

    vector<lg> a(n), b(m), pref;
    FOR(i, 0, n) cin >> a[i];
    FOR(i, 0, m) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    pref = b;
    FOR(i, 1, m) pref[i] += pref[i-1];

    int j=m-1;
    lg res = 0;
    FOR(i, 0, n) {
        while (j >= 0 && a[i] + b[j] >= p) --j;
        res += p * (lg)(m-1-j);
        if (j >= 0) res += pref[j] + (lg)(j+1) * a[i];
    }
    cout << res;
}