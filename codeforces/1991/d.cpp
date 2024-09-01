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
        if (n <= 6) {
            cout << n/2 + 1 << '\n';
            FOR(i, 1, n+1) cout << i/2 + 1 << ' ';
            cout << '\n';
            return;
        }

        cout << "4\n";
        FOR(i, 0, n) cout << i%4 + 1 << ' ';
        cout << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}