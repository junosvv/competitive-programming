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
        vi b = a;
        FOR(i, 1, n) b[i] = max(b[i], b[i-1]);
        FOR(i, 0, n) b[i] -= a[i];
        cout << accumulate(b.begin(), b.end(), 0LL) + *max_element(b.begin(), b.end()) << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}