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

    auto solve = [&]() {
        int n, k;
        cin >> n >> k;
        vi a(n);
        int u = 1;
        for (int i = k-1; i < n; i+=k) {
            a[i] = u++;
        }
        FOR(i, 0, n) if (!a[i]) a[i] = u++;
        for (int i : a) cout << i << ' ';
        cout << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}