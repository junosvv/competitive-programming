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
        vi cnt(n+1);
        FOR(i, 0, n) {
            int x;
            cin >> x;
            ++cnt[x];
        }
        vi a;
        FOR(i, 0, n+1) if (cnt[i]) a.push_back(cnt[i]);
        n = a.size();

        // for (int i : a) cout << i << ' ';
        // cout << '\n';
        
        vi dp(n+1);
        ROF(i, n-1, -1) {
            vi dp2 = dp;
            FOR(k, 0, n) {
                if (a[i] + k <= i) {
                    dp2[k] = max(dp2[k], 1 + dp[k + a[i] + 1]);
                }
            }
            dp = dp2;
            // for (int t : dp) cout << t << ' ';
            // cout << '\n';
        }
        cout << n - dp[0] << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}