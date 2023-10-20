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

    int n, k;
    cin >> n >> k;
    vi a(n);
    FOR(i, 0, n) cin >> a[i];
    
    vi dp(n, 1e9);
    dp[0] = 0;
    FOR(i, 1, n) {
        FOR(j, 1, min(i+1, k+1)) mini(dp[i], dp[i-j] + abs(a[i] - a[i-j]));
    }
    cout << dp[n-1];
}