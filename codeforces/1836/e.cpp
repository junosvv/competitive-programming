#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define vi vector<int>
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
 
    auto solve = [&]() {
        int k;
        cin >> k;
        int n = 1<<(k+1);
        vi a0(n);
        FOR(i, 0, n) cin >> a0[i];
        vi a(n+1);
        FOR(i, 1, n+1) a[i] = a[i-1] ^ a0[i-1];
        ++n;

        vi last(n/2, -1);
        vi ls, rs;
        FOR(i, 0, n) {
            int x = a[i] >> k;
            if (last[x] != -1) {
                ls.push_back(last[x]);
                rs.push_back(i);
            }
            last[x] = i;
        }

        last.assign(n/2, -1);
        FOR(i, 0, ls.size()) {
            int x = a[ls[i]] ^ a[rs[i]];
            if (last[x] != -1) {
                vi res = {ls[last[x]], rs[last[x]], ls[i], rs[i]};
                sort(res.begin(), res.end());
                FOR(i, 0, 4) cout << res[i] + !(i&1) << ' ';
                cout << '\n';
                return;
            }
            last[x] = i;
        }
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}