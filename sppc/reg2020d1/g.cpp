#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    vi a(n);
    FOR(i, 0, n) cin >> a[i];
    if (n == 1) {
        cout << 0;
        exit(0);
    }
    sort(a.begin(), a.end());

    int res = 1e10;
    FOR(i, 1, n) res = min(res, a[i] - a[i-1]);
    cout << res;
}