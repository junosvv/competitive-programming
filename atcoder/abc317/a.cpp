#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, h, x;
    cin >> n >> h >> x;
    vi a(n);
    FOR(i, 0, n) cin >> a[i];

    FOR(i, 0, n) {
        if (h + a[i] >= x) {
            cout << i+1;
            exit(0);
        }
    }
}