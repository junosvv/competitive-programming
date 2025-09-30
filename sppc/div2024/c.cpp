#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int H, n, m, L;
    cin >> H >> n >> m >> L;

    vi p(n), s(m);
    FOR(i, 0, n) cin >> p[i];
    FOR(i, 0, m) cin >> s[i];
    sort(p.begin(), p.end(), greater<int>());
    sort(s.begin(), s.end(), greater<int>());

    long double res = H;
    FOR(k, 0, L+1) {
        long double h = H;
        FOR(i, 0, min(k, n)) if (h > 0) h *= (long double)(100-p[i])/100;
        FOR(i, 0, min(L-k, m)) h -= s[i];
        res = min(res, h);
    }
    cout << setprecision(20) << res;
}