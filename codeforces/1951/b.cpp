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
        FOR(i, 0, n) cin >> a[i];
        k = a[k-1];

        FOR(i, 0, n) {
            if (a[i] == k) {
                FOR(j, i+1, n) {
                    if (a[j] > k) {
                        cout << j-1 << '\n';
                        return;
                    }
                }
                cout << n-1 << '\n';
                return;
            }
            if (a[i] > k) {
                FOR(j, i+1, n) {
                    if (a[j] >= k) {
                        cout << max(i-1, j-max(i, 1LL)) << '\n';
                        return;
                    }
                }
                assert(false);
            }
        }
        assert(false);
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}