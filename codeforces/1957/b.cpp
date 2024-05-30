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

        if (n == 1) {
            cout << k << '\n';
            return;
        }

        int x = 1;
        while (2*x-1 <= k) x <<= 1;
        --x;

        cout << x << ' ' << k-x << ' ';
        FOR(i, 0, n-2) cout << "0 ";
        cout << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}