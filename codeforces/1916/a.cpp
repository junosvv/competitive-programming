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
        vi a(n), cnt(18);
        FOR(i, 0, n) cin >> a[i];
        FOR(i, 0, n) {
            while (a[i] % 7 == 0) {
                a[i] /= 7;
                ++cnt[7];
            }
            while (a[i] % 17 == 0) {
                a[i] /= 17;
                ++cnt[17];
            }
            if (a[i] != 1) {
                cout << "NO\n";
                return;
            }
        }
        int res = 2023;
        if (cnt[7] > 1 || cnt[17] > 2) {
            cout << "NO\n";
            return;
        }
        FOR(i, 0, cnt[7]) res /= 7;
        FOR(i, 0, cnt[17]) res /= 17;
        cout << "YES\n" << res << ' ';
        FOR(i, 0, k-1) cout << "1 ";
        cout << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}