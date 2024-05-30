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
        int x;
        cin >> x;
        cout << "32\n";
        vi a(36), b(36);
        FOR(d, 0, 32) {
            a[d+2] = x>>d & 1LL;
            cout << a[d+2];
        }
        cout << '\n';
        int prev = 0;
        FOR(d, 2, 34) {
            if (a[d-2] && a[d-1] && !a[d] || !a[d-1] && a[d] && !a[d+1]) b[d] = 1;
            if (!a[d-1] && a[d] && a[d+1]) b[d] = -1;
            if (b[d] && b[d-1]) {
                if (b[d-1] == -1) {
                    b[d-1] = 1;
                    b[d] = 0;
                } else {
                    // b[d-1] == 1
                    b[d-1] = -1;
                    b[d] = 0;
                    b[d+1] = 1;
                }
            }
        }
        FOR(d, 2, 34) cout << b[d] << ' ';
        cout << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}