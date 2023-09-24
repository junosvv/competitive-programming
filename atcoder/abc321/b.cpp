#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, x;
    cin >> n >> x;
    vi a(n-1);
    FOR(i, 0, n-1) cin >> a[i];
    
    int res = -1;
    ROF(k, 100, -1) {
        vi a0 = a;
        a.push_back(k);
        sort(a.begin(), a.end());
        int cur = 0;
        FOR(i, 1, n-1) cur += a[i];
        if (cur >= x) res = k;
        a = a0;
    }
    cout << res;
}