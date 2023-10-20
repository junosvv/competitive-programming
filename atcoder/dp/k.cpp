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

    int n, k;
    cin >> n >> k;
    vi a(n);
    FOR(i, 0, n) cin >> a[i];

    vi dp(k+1);
    FOR(i, *min_element(a.begin(), a.end()), k+1) {
        for (int j : a) if (i-j >= 0) dp[i] |= !dp[i-j];
    }
    cout << (dp[k] ? "First" : "Second");
}