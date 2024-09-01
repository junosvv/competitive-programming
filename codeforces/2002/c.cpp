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
        vi x(n), y(n);
        FOR(i, 0, n) cin >> x[i] >> y[i];
        int xs, ys, xe, ye;
        cin >> xs >> ys >> xe >> ye;

        int sqd = (xs-xe)*(xs-xe) + (ys-ye)*(ys-ye);
        FOR(i, 0, n) {
            int cur = (x[i]-xe)*(x[i]-xe) + (y[i]-ye)*(y[i]-ye);
            if (cur <= sqd) {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}