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
    
    int n;
    cin >> n;
    vi a(n+2);
    FOR(i, 1, n+1) cin >> a[i];

    vvi dp(n+2, vi(n+2));
    int turn = n&1;
    FOR(s, 0, n) {
        FOR(i, 1, n+1-s) {
            int j = i+s;
            if (turn) {
                // Taro
                dp[i][j] = max(a[i] + dp[i+1][j], a[j] + dp[i][j-1]);
            } else {
                // Jiro
                dp[i][j] = min(-a[i] + dp[i+1][j], -a[j] + dp[i][j-1]);
            }
        }
        turn ^= 1;
    }
    cout << dp[1][n];
}