#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define vi vector<int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    vi a(n);
    FOR(i, 0, n) cin >> a[i];
    vi pref(n);
    FOR(i, 2, n) {
        pref[i] = pref[i-1];
        if (!(i&1)) pref[i] += a[i] - a[i-1];
    }

    int Q;
    cin >> Q;
    FOR(i, 0, q) {
        int l, r;
        cin >> l >> r;
        int li = lower_bound(a.begin(), a.end(), l) - a.begin();
        if (!(li&1)) 
    }
}