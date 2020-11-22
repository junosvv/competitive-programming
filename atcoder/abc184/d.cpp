#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define int long long
#define vi vector<int>
#define dub long double

template <class T> ostream& operator<<(ostream& os, vector<T>& x) {
    os << '[';
    bool first = true;
    for (T& i : x) {
        if (!first) os << ", ";
        first = false;
        os << i;
    }
    return os << ']';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    const int BIG = 100;
    dub dp[BIG+1][BIG+1][BIG+1];
    FOR(i, 0, BIG+1) FOR(j, 0, BIG+1) {
        dp[BIG][i][j] = 0;
        dp[i][BIG][j] = 0;
        dp[i][j][BIG] = 0;
    }
    ROF(i, BIG-1, -1) ROF(j, BIG-1, -1) ROF(k, BIG-1, -1) {
        dp[i][j][k] = 1 + (dub)(i*dp[i+1][j][k] + j*dp[i][j+1][k] + k*dp[i][j][k+1]) / (i+j+k);
    }
    
    int a, b, c;
    cin >> a >> b >> c;
    cout << setprecision(20) << dp[a][b][c];
}
