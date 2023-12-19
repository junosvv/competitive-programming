#include <bits/stdc++.h>
using namespace std;

#define int long long
#define dub long double
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
    vector<dub> probs(n);
    FOR(i, 0, n) cin >> probs[i];

    vector<dub> dp = {1, 0};
    for (dub p : probs) {
        vector<dub> dp2 = dp;
        FOR(i, 0, dp2.size()) {
            dp2[i] = (1-p) * dp[i];
            if (i-1 >= 0) dp2[i] += p * dp[i-1];
        }
        dp = dp2;
        dp.push_back(0);
    }

    dub res = 0;
    FOR(i, n/2+1, n+1) res += dp[i];
    cout << setprecision(10) << res;
}