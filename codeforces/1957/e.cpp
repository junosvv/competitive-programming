#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

const int MOD = 1e9+7;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    const int BIG = 1e6 + 1;
    vi dp(BIG), sieve(BIG);
    FOR(p, 2, BIG) {
        if (!sieve[p]) {
            for (int u=p; u<BIG; u+=p) --dp[u];
            for (int u=p; u<BIG; u+=p*p) dp[u] += p;
        }
        for (int u=p*p; u<BIG; u+=p) sieve[u] = 1;
    }
    FOR(u, 1, BIG) dp[u] = (dp[u] + dp[u-1]) % MOD;
    FOR(u, 4, BIG) if (u%8 >= 4) dp[u] = (dp[u] + 2) % MOD;
    FOR(u, 1, BIG) dp[u] = (dp[u] + dp[u-1]) % MOD;

    auto solve = [&]() {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}