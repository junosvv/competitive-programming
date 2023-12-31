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
        int n;
        cin >> n;
        vi a(n);
        FOR(i, 0, n) cin >> a[i];

        int odds = 0;
        int sum = 0;
        FOR(i, 0, n) {
            sum += a[i];
            if (a[i]&1) ++odds;
            int bonus = 0;
            if (odds % 3 == 1) bonus = 1;
            if (i == 0) cout << a[i] << ' ';
            else cout << sum - odds/3 - bonus << ' ';
        }
        cout << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}