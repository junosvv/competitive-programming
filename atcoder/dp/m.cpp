#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define SQ(x) (x)*(x)

void maxi(int& a, int b) {
    a = max(a, b);
}
void mini(int& a, int b) {
    a = min(a, b);
}

const int MOD = 1e9+7;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, K;
    cin >> n >> K;
    vi a(n);
    FOR(i, 0, n) cin >> a[i];

    vi dp(K+1);
    dp[0] = 1;
    FOR(i, 0, n) {
        vi dp2(K+1);
        int pref = 0;
        FOR(k, 0, K+1) {
            pref = (pref + dp[k]) % MOD;
            if (k-a[i]-1 >= 0) pref = (pref + MOD-dp[k-a[i]-1]) % MOD;
            dp2[k] = pref;
        }
        dp = dp2;
    }
    cout << dp[K];
}