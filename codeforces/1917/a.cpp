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
        int prod = 1;
        FOR(i, 0, n) {
            cin >> a[i];
            if (a[i] != 0) a[i] /= abs(a[i]);
            prod *= a[i];
        }
        if (prod > 0) cout << "1\n1 0\n";
        else cout << "0\n";
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}