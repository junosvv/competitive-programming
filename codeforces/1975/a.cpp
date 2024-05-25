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
        
        FOR(i, 1, n) {
            if (a[i] < a[i-1]) {
                if (a[n-1] > a[0]) {
                    cout << "No\n";
                    return;
                }
                FOR(j, i+1, n) {
                    if (a[j] < a[j-1]) {
                        cout << "No\n";
                        return;
                    }
                }
                cout << "Yes\n";
                return;
            }
        }
        cout << "Yes\n";
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}