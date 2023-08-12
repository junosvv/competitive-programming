#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>

const int MOD = 998244353;
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vi a(n);
    FOR(i, 0, n) {
        char c;
        cin >> c;
        a[i] = c-'0';
    }
    FOR(i, 1, n) if (a[i-1] >= 2 && a[i] >= 2) {
        cout << -1;
        exit(0);
    }

    int res = 0;
    ROF(i, n-1, 0) res = (res+1) * a[i] % MOD;
    cout << res;
}