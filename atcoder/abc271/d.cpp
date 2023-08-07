#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, s;
    cin >> n >> s;
    vvi a(2, vi(n));
    FOR(i, 0, n) cin >> a[0][i] >> a[1][i];

    const int BIG = 10001;
    vvi dp(n+1, vi(BIG, -1));
    dp[0][0] = 0;
    FOR(i, 0, n) {
        ROF(x, s, -1) {
            FOR(d, 0, 2) if (x-a[d][i] >= 0) {
                if (dp[i][x-a[d][i]] >= 0) {
                    dp[i+1][x] = d;
                }
            }
        }
    }
    if (dp[n][s] == -1) {
        cout << "No";
    } else {
        cout << "Yes\n";
        int x = s;
        string res;
        ROF(i, n, 0) {
            res += "HT"[dp[i][x]];
            x -= a[dp[i][x]][i-1];
        }
        reverse(res.begin(), res.end());
        cout << res;
    }
}