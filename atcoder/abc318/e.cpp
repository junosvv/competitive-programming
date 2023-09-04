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

    vi latest(n+1, -1), prev(n), b(n), c(n), bpref(n);
    int res = 0;
    FOR(i, 0, n) {
        prev[i] = latest[a[i]];
        if (prev[i] != -1) {
            b[i] = b[prev[i]] + i - prev[i] - 1;
            c[i] = c[prev[i]] + 1;
            bpref[i] = bpref[prev[i]];
            res += b[i] * c[i] - bpref[i];
            bpref[i] += b[i];
        }
        latest[a[i]] = i;
    }
    cout << res;
}