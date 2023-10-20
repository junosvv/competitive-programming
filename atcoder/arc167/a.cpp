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
    
    int n, m;
    cin >> n >> m;
    m = n-m;
    vi a(n);
    FOR(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());

    int res = 0;
    FOR(i, 0, n) res += a[i]*a[i];
    FOR(i, 0, m) res += 2 * a[i] * a[2*m-1-i];
    cout << res;
}