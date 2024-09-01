#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define t3i tuple<int,int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    auto solve = [&]() {
        int n;
        cin >> n;
        vi b(n-1);
        FOR(i, 0, n-1) cin >> b[i];

        vi a(n);
        FOR(i, 0, n-1) {
            a[i] |= b[i];
            a[i+1] |= b[i];
        }

        FOR(i, 0, n-1) {
            if ((a[i] & a[i+1]) != b[i]) {
                cout << "-1\n";
                return;
            }
        }
        for (int i : a) cout << i << ' ';
        cout << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}