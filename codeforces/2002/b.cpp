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
        vi a(n), b(n);
        FOR(i, 0, n) cin >> a[i];
        FOR(i, 0, n) cin >> b[i];
        vi rb = b;
        reverse(rb.begin(), rb.end());
        if (a == b || a == rb) cout << "Bob\n";
        else cout << "Alice\n";
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}