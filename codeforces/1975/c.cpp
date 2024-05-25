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

        vi b(n);
        map<int,vi> loc;
        FOR(i, 0, n) loc[-a[i]].push_back(i);
        for (auto pr : loc) {
            for (int l : pr.second) {
                FOR(i, l-2, l+3) {
                    if (i < 0 || i >= n) continue;
                    if (b[i]) {
                        cout << -pr.first << '\n'; 
                        return;
                    }
                }
                b[l] = 1;
            }
        }
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}