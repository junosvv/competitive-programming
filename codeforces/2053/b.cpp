#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    auto solve = [&]() {
        int n;
        cin >> n;
        vi l(n), r(n), pref(2*n+1), cnt(2*n+1);
        FOR(i, 0, n) {
            cin >> l[i] >> r[i];
            if (l[i] == r[i]) {
                ++cnt[l[i]];
                pref[l[i]] = 1;
            }
        }
        FOR(i, 1, 2*n+1) pref[i] += pref[i-1];

        vi res(n);
        FOR(i, 0, n) {
            if (l[i] == r[i]) {
                res[i] = cnt[l[i]] == 1;
            } else {
                res[i] = pref[r[i]] - pref[l[i]-1] != r[i]-l[i]+1;
            }
        }
        for (int i : res) cout << i;
        cout << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}