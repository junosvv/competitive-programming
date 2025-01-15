#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    auto solve = [&]() {
        int n;
        cin >> n;
        vi a(n);
        FOR(i, 0, n) cin >> a[i];
        FOR(i, 1, n) {
            int u = a[i-1], v = a[i];
            if (u > v) swap(u, v);
            if (v < 2*u) {
                cout << "YES\n";
                return;
            }
        }
        cout << "NO\n";
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}