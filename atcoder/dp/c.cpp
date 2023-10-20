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
    
    int n;
    cin >> n;
    vvi grid(n, vi(3));
    FOR(i, 0, n) FOR(j, 0, 3) cin >> grid[i][j];

    vi dp(3);
    FOR(i, 0, n) {
        vi dp2(3);
        FOR(j, 0, 3) {
            FOR(k, 0, 3) if (k != j) maxi(dp2[j], dp[k]);
            dp2[j] += grid[i][j];
        }
        dp = dp2;
    }
    cout << max({dp[0], dp[1], dp[2]});
}