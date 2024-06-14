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
        int n, m, k;
        cin >> n >> m >> k;
        vi a(n);
        FOR(i, 0, n) cin >> a[i];
        sort(a.begin(), a.end());
        int res = k*(k-1)/2;
        FOR(i, 0, n) {
            int buy = min(k, m);
            // cout << "buying " << buy << " at " << a[i] << '\n';
            k -= buy;
            res += buy * (2*a[i] - buy + 1) / 2;
            if (k == 0) break;
        }
        cout << res << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}