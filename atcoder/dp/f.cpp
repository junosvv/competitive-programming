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

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();

    vvi dp(n+1, vi(m+1));
    vvi parA = dp, parB = dp;
    FOR(i, 1, n+1) FOR(j, 1, m+1) {
        if (s[i-1] == t[j-1]) {
            dp[i][j] = 1 + dp[i-1][j-1];
            parA[i][j] = i-1;
            parB[i][j] = j-1;
        } else {
            if (dp[i-1][j] >= dp[i][j-1]) {
                dp[i][j] = dp[i-1][j];
                parA[i][j] = i-1;
                parB[i][j] = j;
            } else {
                dp[i][j] = dp[i][j-1];
                parA[i][j] = i;
                parB[i][j] = j-1;
            }
        }
    }

    string res;
    int i = n, j = m;
    while (i >= 1 && j >= 1) {
        if (s[i-1] == t[j-1]) res += s[i-1];
        int temp = parA[i][j];
        j = parB[i][j];
        i = temp;
    }
    reverse(res.begin(), res.end());
    cout << res;
}