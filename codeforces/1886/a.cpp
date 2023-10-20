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
        if (n%3) {
            if (n <= 5) {
                cout << "NO\n";
                return;
            }
            cout << "YES\n";
            cout << "1 2 " << n-3 << '\n';
            return;
        }
        if (n <= 9) {
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
        cout << "1 4 " << n-5 << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}