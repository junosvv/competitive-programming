#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, d, p;
    cin >> n >> d >> p;
    vi a(n);
    FOR(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());
    FOR(i, 1, n) a[i] += a[i-1];

    int res = a.back();
    int i = n-1;
    int cost = 0;
    while (i >= 0) {
        i -= d;
        cost += p;
        res = min(res, (i < 0 ? 0 : a[i]) + cost);
    }
    cout << res;
}