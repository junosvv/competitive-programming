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
        vi a(2);
        FOR(i, 0, n) {
            char x;
            cin >> x;
            ++a[x-'0'];
        }
        vi b(n-1);
        FOR(i, 0, n-1) {
            char x;
            cin >> x;
            b[i] = '1'-x;
        }
        if (a[0] == 0 || a[1] == 0) {
            cout << "NO\n";
            return;
        }
        for (int i : b) {
            --a[i];
            if (a[i] == 0) {
                if (a[!i] == 1) cout << "YES\n";
                else cout << "NO\n";
                return;
            }
        }
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}