#include <bits/stdc++.h>
using namespace std;

#define int long long
#define dub long double
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define vd vector<dub>
#define vvd vector<vd>
#define vvvd vector<vvd>
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
    vi a(n);
    vi init(4);
    FOR(_, 0, n) {
        int x;
        cin >> x;
        ++init[x];
    }
    
    vvvd dp(n+1, vvd(n+1, vd(n+1)));
    FOR(n3, 0, n+1) {
        FOR(n2, 0, n-n3+1) {
            FOR(n1, 0, n-n3-n2+1) if (!(n1==0 && n2==0 && n3==0)) {
                dp[n1][n2][n3] = n;
                if (n1 >= 1) dp[n1][n2][n3] += n1 * dp[n1-1][n2][n3];
                if (n2 >= 1) dp[n1][n2][n3] += n2 * dp[n1+1][n2-1][n3];
                if (n3 >= 1) dp[n1][n2][n3] += n3 * dp[n1][n2+1][n3-1];
                dp[n1][n2][n3] /= n1+n2+n3;
            }
        }
    }
    cout << setprecision(10) << dp[init[1]][init[2]][init[3]];
}