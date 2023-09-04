#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    auto solve = [&]() {
        int n;
        cin >> n;
        vi a(n);
        FOR(i, 0, n) cin >> a[i];
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        FOR(i, 1, n) if (a[i] != a[i-1]) {
            cout << n-i << ' ' << i << '\n';
            FOR(j, i, n) cout << a[j] << ' ';
            cout << '\n';
            FOR(j, 0, i) cout << a[j] << ' ';
            cout << '\n';
            return;
        }
        cout << -1 << '\n';
        return;
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}