#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

const int MOD = 998244353;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    const int BIG = 5001;
    vvi choose(BIG, vi(BIG));
    FOR(k, 0, BIG) choose[k][0] = choose[k][k] = 1;
    FOR(k, 1, BIG) FOR(r, 1, k) choose[k][r] = (choose[k-1][r-1] + choose[k-1][r]) % MOD;

    auto solve = [&]() {
        int n;
        cin >> n;
        ++n;
        vi p(n);
        FOR(i, 1, n) cin >> p[i];
        sort(p.begin(), p.end());
        int range = p[n-1] - p[0];
        
        int res = 0;
        FOR(s, 0, range+1) {
            vi cnt(range+1);
            FOR(i, 0, n) ++cnt[p[i]-p[0]];

            vi atm(range+1);
            ROF(i, 0, p[0]-1) ++atm[i-p[0]];
            FOR(i, p[0]+1, p[0]+1+s) ++atm[i-p[0]];

            // cout << "\ncnt: ";
            // for (int i : cnt) cout << i << ' ';
            // cout << "\natm: ";
            // for (int i : atm) cout << i << ' ';
            // cout << '\n';

            int cur = 1;
            FOR(i, 0, range) {
                if (atm[i] == 0 || atm[i] > cnt[i]) {
                    cur = 0;
                    break;
                }
                cur = cur * choose[cnt[i]-1][atm[i]-1] % MOD;
                atm[i+1] += cnt[i]-atm[i];
                atm[i] = cnt[i];

                // cout << "cur: " << cur << ", proc " << i+p[0] << ": ";
                // for (int i : atm) cout << i << ' ';
                // cout << '\n';
            }
            if (atm[range] != cnt[range]) cur = 0;
            res = (res + cur) % MOD;
        }
        cout << res << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}