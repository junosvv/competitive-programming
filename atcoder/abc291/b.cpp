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
    vi a(5*n);
    FOR(i, 0, 5*n) cin >> a[i];
    sort(a.begin(), a.end());
    double res = 0;
    FOR(i, n, 4*n) res += a[i];
    res /= 3*n;
    cout << setprecision(20) << res;
}