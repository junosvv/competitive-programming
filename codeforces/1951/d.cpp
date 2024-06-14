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
        if (n == k) {
            cout << "YES\n1\n1\n";
            return;
        }
        if (n < 2*k-1) {
            cout << "NO\n";
            return;
        }
        cout << "YES\n2\n" << n-k+1 << " 1\n";
        return;
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}