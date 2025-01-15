#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    auto solve = [&]() {
        int n;
        cin >> n;
        vector<string> a(2);
        cin >> a[0] >> a[1];

        vi dp = {0, 0, 1};
        vi dprev = dp;
        FOR(i, 0, n) {
            if (a[0][i] != a[1][i]) {
                int x = a[0][i] == '.' ? 0 : 1;
                swap(dp, dprev);
                dp.assign(3, (i-1 >= 0 && a[x][i-1] == '.' ? dprev[!x] : 0));
                dp[!x] = dprev[2];
            } else {
                vi dp2 = dp;
                if (a[0][i] == '.') {
                    dp2 = {(i-1 >= 0 && a[0][i-1] == '.' ? dp[1] : 0), (i-1 >= 0 && a[1][i-1] == '.' ? dp[0] : 0), dp[2] + (i-1 >= 0 && a[0][i-1] == '.' && a[1][i-1] == '.' ? dprev[2] : 0)};
                }
                dprev = dp;
                dp = dp2;
            }
            for (int &i : dp) i = min(i, 2LL);
        }
        if (dp[2] == 0) cout << "None\n";
        else if (dp[2] == 1) cout << "Unique\n";
        else cout << "Multiple\n";
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}