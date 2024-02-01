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
        vi l(n), r(n), c(n);
        FOR(i, 0, n) cin >> l[i];
        FOR(i, 0, n) cin >> r[i];
        FOR(i, 0, n) cin >> c[i];
        sort(l.begin(), l.end());
        sort(r.begin(), r.end());
        sort(c.rbegin(), c.rend());
        vi stack, lengths;
        int j = 0;
        FOR(i, 0, n) {
            while (j < n && l[j] < r[i]) stack.push_back(l[j++]);
            lengths.push_back(r[i]-stack.back());
            stack.pop_back();
        }
        sort(lengths.begin(), lengths.end());
        int res = 0;
        FOR(i, 0, n) res += lengths[i]*c[i];
        cout << res << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}