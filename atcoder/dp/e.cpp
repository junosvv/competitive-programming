#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

void maxi(int& a, int b) {
    a = max(a, b);
}
void mini(int& a, int b) {
    a = min(a, b);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, W;
    cin >> n >> W;
    vi v(n), w(n);
    FOR(i, 0, n) cin >> w[i] >> v[i];

    const int BIG = 1e5+1;
    vi dp(BIG, W+1);
    dp[0] = 0;
    FOR(i, 0, n) {
        vi dp2 = dp;
        FOR(j, 0, BIG-v[i]) {
            mini(dp2[j+v[i]], dp[j] + w[i]);
        }
        dp = dp2;
    }
    ROF(i, BIG-1, -1) if (dp[i] <= W) {
        cout << i;
        break;
    }
}