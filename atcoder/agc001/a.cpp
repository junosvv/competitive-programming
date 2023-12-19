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
    vi a(2*n);
    FOR(i, 0, 2*n) cin >> a[i];
    sort(a.begin(), a.end());

    int res = 0;
    FOR(i, 0, n) res += a[2*i];
    cout << res;
}