#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vi a(n);
        FOR(i, 0, n) cin >> a[i];
        bool fail = true;
        FOR(i, 0, n) if (a[i]) fail = false;
        if (fail) cout << "NO\n";
        else cout << "YES\n";
    }
}