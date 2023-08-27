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
#define pii pair<int,int>
#define vs vector<string>
#define SQ(x) (x)*(x)

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vi x(n), y(n);
    FOR(i, 0, n) cin >> x[i] >> y[i];

    auto euc = [&](int i, int j) {
        return sqrt(SQ(x[i]-x[j]) + SQ(y[i]-y[j]));
    };

    const int BIG = 31;
    vi p(BIG);
    p[1] = 1;
    FOR(i, 2, BIG) p[i] = 2*p[i-1];

    vvd dp(n, vd(BIG, 1e9));
    dp[0][0] = 0;
    FOR(i, 1, n) {
        FOR(k, 0, BIG) {
            FOR(l, 0, k+1) if (i-1-l >= 0) {
                dp[i][k] = min(dp[i][k], dp[i-1-l][k-l] + euc(i-1-l, i) + p[k] - p[k-l]);
            }
        }
    }
    cout << setprecision(15) << *min_element(dp[n-1].begin(), dp[n-1].end());
}