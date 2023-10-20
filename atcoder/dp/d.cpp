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

    vi dp(W+1);
    FOR(i, 0, n) {
        vi dp2 = dp;
        FOR(j, 0, W+1-w[i]) maxi(dp2[j+w[i]], dp[j] + v[i]);
        dp = dp2;
    }
    cout << *max_element(dp.begin(), dp.end());
}